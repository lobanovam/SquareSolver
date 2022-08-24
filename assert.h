#ifndef ASSERT_H_INCLUDED
#define ASSERT_H_INCLUDED

#define ASSERT(condition)                                               \
    if(!(condition))                                                    \
    {                                                                   \
    fprintf(stderr, "Error in %s\n FILE: %s\n LINE: %d\n FUNC: %s\n",   \
             #condition, __FILE__, __LINE__, __PRETTY_FUNCTION__);      \
    }

#endif // ASSERT_H_INCLUDED
