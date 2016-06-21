#include "EmitterException.h"
#include "ModuleEmitter.h"

namespace emll
{
	namespace compiler
	{
		namespace ir
		{
			ModuleEmitter::ModuleEmitter(LLVMEmitter* pEmitter, std::unique_ptr<llvm::Module> pModule)
				: _pEmitter(pEmitter),
				_pModule(std::move(pModule))
			{
			}

			FunctionEmitter ModuleEmitter::AddMain()
			{
				return Function("main", ValueType::Void, true);
			}

			llvm::Function* ModuleEmitter::GetFunction(const std::string& name)
			{
				return _pModule->getFunction(name);
			}

			FunctionEmitter ModuleEmitter::Function(const std::string& name, ValueType returnType, ValueTypeList* pArgs, bool isPublic)
			{
				llvm::Function* pfn = _pEmitter->Function(Module(), name, returnType, Linkage(isPublic), pArgs);
				if (pfn == nullptr)
				{
					throw new EmitterException(EmitterError::InvalidFunction);
				}
				BeginFunction(pfn);
				return FunctionEmitter(_pEmitter, pfn);
			}

			FunctionEmitter ModuleEmitter::Function(const std::string& name, ValueType returnType, NamedValueTypeList& args, bool isPublic)
			{
				llvm::Function* pfn = _pEmitter->Function(Module(), name, returnType, Linkage(isPublic), args);
				if (pfn == nullptr)
				{
					throw new EmitterException(EmitterError::InvalidFunction);
				}
				BeginFunction(pfn);
				return FunctionEmitter(_pEmitter, pfn);
			}

			FunctionEmitter ModuleEmitter::Function(const std::string& name, ValueType returnType, std::initializer_list<ValueType> args, bool isPublic)
			{
				_valueTypeList.init(args);
				return Function(name, returnType, &_valueTypeList, isPublic);
			}

			llvm::Function::LinkageTypes ModuleEmitter::Linkage(bool isPublic)
			{
				return isPublic ?
					llvm::Function::LinkageTypes::ExternalLinkage :
					llvm::Function::LinkageTypes::InternalLinkage;
			}

			void ModuleEmitter::BeginFunction(llvm::Function* pfn)
			{
				//
				// Set us up with a default entry point, since we'll always need one
				// We may add additional annotations here
				//
				auto pBlock = _pEmitter->Block(pfn, "entry");
				_pEmitter->SetCurrentBlock(pBlock);
			}

			void ModuleEmitter::WriteToFile(const std::string& filePath, bool isBitCode)
			{
				std::error_code error;

				auto openFlags = isBitCode ?
					llvm::sys::fs::F_None :
					llvm::sys::fs::F_Text;
				llvm::tool_output_file out(filePath, error, openFlags);
				if (error) {
					throw new LLVMException(error);
				}

				if (isBitCode)
				{
					llvm::WriteBitcodeToFile(_pModule.get(), out.os());
				}
				else
				{
					Module()->print(out.os(), nullptr);
				}
				if (out.os().has_error()) {
					throw new EmitterException(EmitterError::WriteModuleFailed);
				}
				out.keep();
			}

			void ModuleEmitter::WriteToStream(std::ostream& os, bool isBitCode)
			{
				llvm::raw_os_ostream out(os);
				if (isBitCode)
				{
					llvm::WriteBitcodeToFile(_pModule.get(), out);
				}
				else
				{
					Module()->print(out, nullptr);
				}
			}
			//
			// Standard C Runtime functions
			//
			void ModuleEmitter::DeclarePrintf()
			{
				llvm::FunctionType* type = llvm::TypeBuilder<void(char*, ...), false>::get(_pEmitter->Context());
				DeclareFunction("printf", type);
			}
			void ModuleEmitter::DeclareMalloc()
			{
				_valueTypeList.init({ ValueType::Int64 });
				DeclareFunction("malloc", ValueType::PByte, _valueTypeList);
			}
			void ModuleEmitter::DeclareFree()
			{
				_valueTypeList.init({ ValueType::PByte });
				DeclareFunction("free", ValueType::Void, _valueTypeList);
			}
		}
	}
}