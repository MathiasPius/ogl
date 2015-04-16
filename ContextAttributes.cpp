#include "Precompiled.h"
#include "Context.h"

using namespace ogl;

context::attributes::attributes() :
my_attributes({0})
{

}

context::attributes::~attributes()
{

}

void context::attributes::add(int aVariable, int aValue)
{
	my_attributes.back() = aVariable;
	my_attributes.emplace_back(aValue);
	my_attributes.emplace_back(0);
}

const int *context::attributes::get() const
{
	return &my_attributes[0];
}