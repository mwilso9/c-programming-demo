#ifndef __STDIO__
#  define __STDIO__
#  include <stdio.h>
#endif

#ifndef __STDLIB__
#  define __STDLIB__
#  include <stdlib.h>
#endif

#ifndef __ASSERT__
#  define __ASSERT__
#  undef NDEBUG
#  include <assert.h>
#endif

int assertLibClass();
