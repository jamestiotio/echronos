/* Applications do not necessarily access all RTOS APIs.
 * Therefore, they are marked as potentially unused for static analysis. */
/*| public_headers |*/
#include <stdint.h>

/*| public_types |*/
typedef uint8_t {{prefix_type}}TimerId;
typedef uint32_t {{prefix_type}}TicksAbsolute;
typedef uint16_t {{prefix_type}}TicksRelative;

/*| public_structures |*/

/*| public_object_like_macros |*/
{{#timers}}
#define {{prefix_const}}TIMER_ID_{{name|u}} (({{prefix_type}}TimerId) UINT8_C({{idx}}))
{{/timers}}

/*| public_function_like_macros |*/

/*| public_state |*/
/*@unused@*/
extern {{prefix_type}}TicksAbsolute {{prefix_func}}timer_current_ticks;

/*| public_function_declarations |*/
/*@unused@*/
void {{prefix_func}}sleep({{prefix_type}}TicksRelative ticks) {{prefix_const}}REENTRANT;
{{#timers.length}}
/*@unused@*/
void {{prefix_func}}timer_enable({{prefix_type}}TimerId timer_id);
/*@unused@*/
void {{prefix_func}}timer_disable({{prefix_type}}TimerId timer_id);
/*@unused@*/
void {{prefix_func}}timer_oneshot({{prefix_type}}TimerId timer_id, {{prefix_type}}TicksRelative timeout);
/*@unused@*/
bool {{prefix_func}}timer_check_overflow({{prefix_type}}TimerId timer_id);
/*@unused@*/
{{prefix_type}}TicksRelative {{prefix_func}}timer_remaining({{prefix_type}}TimerId timer_id);
/*@unused@*/
void {{prefix_func}}timer_reload_set({{prefix_type}}TimerId timer_id, {{prefix_type}}TicksRelative reload);
/*@unused@*/
void {{prefix_func}}timer_error_set({{prefix_type}}TimerId timer_id, {{prefix_type}}ErrorId error_id);
/*@unused@*/
void {{prefix_func}}timer_signal_set({{prefix_type}}TimerId timer_id, {{prefix_type}}TaskId task_id, {{prefix_type}}SignalSet signal_set);
{{/timers.length}}

/*| public_privileged_function_declarations |*/
