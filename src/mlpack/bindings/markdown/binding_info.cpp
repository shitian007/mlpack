/**
 * @file binding_info.cpp
 * @author Ryan Curtin
 *
 * Implementation of BindingInfo functions.
 */
#include "binding_info.hpp"

using namespace std;

namespace mlpack {
namespace bindings {
namespace markdown {

util::ProgramDoc& BindingInfo::GetProgramDoc(const std::string& bindingName)
{
  if (GetSingleton().map.count(bindingName) == 0)
  {
    throw std::invalid_argument("Binding name '" + bindingName +
        "' not known!");
  }

  return GetSingleton().map.at(bindingName);
}

/**
 * Register a ProgramDoc object with the given bindingName.
 */
void BindingInfo::RegisterProgramDoc(const std::string& bindingName,
                                     const util::ProgramDoc& programDoc)
{
  GetSingleton().map[bindingName] = programDoc;
}

//! Get or modify the current language (don't set it to something invalid!).
std::string& BindingInfo::Language()
{
  return GetSingleton().language;
}

BindingInfo& BindingInfo::GetSingleton()
{
  static BindingInfo instance;
  return instance;
}

} // namespace markdown
} // namespace bindings
} // namespace mlpack
