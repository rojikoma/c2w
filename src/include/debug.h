/* For simple line tracing,
 * use C2W_PRINT(TRACE_LINE);
 */
#define C2W_PRINT(fmt, args...)     printf("[%s:%d]"fmt, __func__, __LINE__, ##args)
#define TRACE_LINE                  "\n"
