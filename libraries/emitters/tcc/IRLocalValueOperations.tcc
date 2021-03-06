////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     IRLocalValueOperations.tcc (emitters)
//  Authors:  Kern Handa
//
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace ell
{
namespace emitters
{
    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator+(ValueType a, IRLocalScalar b)
    {
        if (b.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<double>(a)) + b;
        }
        else if (b.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<int64_t>(a)) + b;
        }

        return b.function.LocalScalar(a) + b;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator+(IRLocalScalar a, ValueType b)
    {
        return b + a;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator-(ValueType a, IRLocalScalar b)
    {
        if (b.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<double>(a)) - b;
        }
        else if (b.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<int64_t>(a)) - b;
        }

        return b.function.LocalScalar(a) - b;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator-(IRLocalScalar a, ValueType b)
    {
        if (a.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return a - a.function.LocalScalar(static_cast<double>(b));
        }
        else if (a.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return a - a.function.LocalScalar(static_cast<int64_t>(b));
        }

        return a - a.function.LocalScalar(b);
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator*(ValueType a, IRLocalScalar b)
    {
        if (b.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<double>(a)) * b;
        }
        else if (b.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<int64_t>(a)) * b;
        }

        return b.function.LocalScalar(a) * b;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator*(IRLocalScalar a, ValueType b)
    {
        return b * a;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator/(ValueType a, IRLocalScalar b)
    {
        if (b.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<double>(a)) / b;
        }
        else if (b.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<int64_t>(a)) / b;
        }

        return b.function.LocalScalar(a) / b;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator/(IRLocalScalar a, ValueType b)
    {
        if (a.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return a / a.function.LocalScalar(static_cast<double>(b));
        }
        else if (a.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return a / a.function.LocalScalar(static_cast<int64_t>(b));
        }

        return a / a.function.LocalScalar(b);
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator==(ValueType a, IRLocalScalar b)
    {
        if (b.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<double>(a)) == b;
        }
        else if (b.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<int64_t>(a)) == b;
        }

        return b.function.LocalScalar(a) == b;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator==(IRLocalScalar a, ValueType b)
    {
        return b == a;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator!=(ValueType a, IRLocalScalar b)
    {
        if (b.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<double>(a)) != b;
        }
        else if (b.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<int64_t>(a)) != b;
        }

        return b.function.LocalScalar(a) != b;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator!=(IRLocalScalar a, ValueType b)
    {
        return b != a;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator<(ValueType a, IRLocalScalar b)
    {
        if (b.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<double>(a)) < b;
        }
        else if (b.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<int64_t>(a)) < b;
        }

        return b.function.LocalScalar(a) < b;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator<(IRLocalScalar a, ValueType b)
    {
        return b >= a;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator<=(ValueType a, IRLocalScalar b)
    {
        if (b.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<double>(a)) <= b;
        }
        else if (b.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<int64_t>(a)) <= b;
        }

        return b.function.LocalScalar(a) <= b;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator<=(IRLocalScalar a, ValueType b)
    {
        return b > a;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator>(ValueType a, IRLocalScalar b)
    {
        if (b.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<double>(a)) > b;
        }
        else if (b.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<int64_t>(a)) > b;
        }

        return b.function.LocalScalar(a) > b;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator>(IRLocalScalar a, ValueType b)
    {
        return b <= a;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator>=(ValueType a, IRLocalScalar b)
    {
        if (b.value->getType()->isFloatingPointTy() && !std::is_floating_point<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<double>(a)) >= b;
        }
        else if (b.value->getType()->isIntegerTy() && !std::is_integral<ValueType>{})
        {
            return b.function.LocalScalar(static_cast<int64_t>(a)) >= b;
        }

        return b.function.LocalScalar(a) >= b;
    }

    template <typename ValueType, utilities::IsFundamental<ValueType> /* = true*/>
    IRLocalScalar operator>=(IRLocalScalar a, ValueType b)
    {
        return b < a;
    }

    template <typename ValueType>
    IRLocalScalar Sigmoid(IRLocalScalar a)
    {
        auto& fn = a.function;

        auto expInput = Exp(a);
        constexpr auto one = static_cast<ValueType>(1);
        auto result = fn.Select(a > ValueType{0}, one / (Exp(-a) + one), expInput / (expInput + one));
        return fn.LocalScalar(result);
    }

    template <typename ValueType>
    IRLocalScalar Tanh(IRLocalScalar a)
    {
        // tanh(x) === (exp(x) - exp(-x)) / (exp(x) + exp(-x))
        //         = 2*sigmoid(2*x) - 1
        auto two = static_cast<ValueType>(2.0);
        return (two * Sigmoid<ValueType>(two * a)) - static_cast<ValueType>(1);
    }
}
}

