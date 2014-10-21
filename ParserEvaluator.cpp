#include "ParserEvaluator.hpp"
#include <string>
#include <boost/lexical_cast.hpp>
#include <muParser.h>

using namespace std;
using namespace psopp;

namespace psopp
{
    struct Implementation
    {
        mu::Parser parser;
    };
}

Parser::Parser(int domain_size_)
{
    variables.resize(domain_size_, 0.0);
    implementation = new Implementation();
    for (size_t i = 0; i < variables.size(); ++i)
    {
        string var_name = "x";
        var_name += boost::lexical_cast<string>(i);
        implementation->parser.DefineVar(var_name.c_str(), &variables[i]);
    }
}

Parser::~Parser()
{
    delete implementation;
}

void Parser::SetExpression(const std::string& expression_)
{
    implementation->parser.SetExpr(expression_);
}

double Parser::Evaluate()
{
    return implementation->parser.Eval();
}