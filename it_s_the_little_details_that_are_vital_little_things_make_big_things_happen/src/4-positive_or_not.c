#include "holbertonschool.h"

void positive_or_not(int n)
{
  if (n>0) /* if greater than 0 */
    print_char('P'); /* print P for positive */
  else if (n==0) /* if it is 0 */
    print_char('Z'); /* print Z for zero */
  else /* otherwise, the number must be negative */
    print_char('N'); /* print N for negative */
}
