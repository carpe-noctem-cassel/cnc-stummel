#include "Test1571239990055.h"
/*PROTECTED REGION ID(eph1571239990055) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/

using namespace alica;

namespace alicaAutogenerated {
// Plan:Test
/* generated comment
    Task: 1570633373655  -> EntryPoint-ID: 1571240000644
*/
shared_ptr<UtilityFunction>
UtilityFunction1571239990055::getUtilityFunction(Plan *plan) {
  /*PROTECTED REGION ID(1571239990055) ENABLED START*/
  std::shared_ptr<UtilityFunction> defaultFunction =
      std::make_shared<DefaultUtilityFunction>(plan);
  return defaultFunction;
  /*PROTECTED REGION END*/
}
} // namespace alicaAutogenerated
