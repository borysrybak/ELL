////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     CompareArguments.cpp (print)
//  Authors:  Chris Lovett
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "CompareArguments.h"

// utilities
#include "Files.h"

namespace ell
{
void ParsedCompareArguments::AddArgs(utilities::CommandLineParser& parser)
{
    parser.AddDocumentationString("Input options");
    parser.AddOption(inputMapFile, "inputMapFile", "imap", "Path to the input *.map file", "");
    parser.AddOption(inputTestFile, "inputTestFile", "itf", "Path to the input test file containing image to process", "");
    parser.AddOption(inputScale, "inputScale", "is", "How to scale input image numbers (default 1/255)", 1.0f / 255.0f);

    parser.AddDocumentationString("Output options");
    parser.AddOption(outputDirectory, "outputDirectory", "od", "Location of output files (default cwd)", "");
    parser.AddOption(writeReport, "report", "", "Generate markdown report", true);
    parser.AddOption(writeGraph, "graph", "", "Write DGML graph", true);

    parser.AddDocumentationString("Code-generation options");
    parser.AddOption(optimize, "optimize", "opt", "Optimize output code", true);
    parser.AddOption(useBlas, "blas", "", "Emit code that calls BLAS", false);
    parser.AddOption(allowVectorInstructions, "vector", "vec", "Emit code that uses vector instructions", false);
    parser.AddOption(bgr, "bgr", "", "Whether to convert test image to BGR format (default RGB)", true);
}
}
