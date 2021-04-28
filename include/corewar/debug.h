#ifndef C0269E7C_BDF2_4097_B8CC_E878150123D4
#define C0269E7C_BDF2_4097_B8CC_E878150123D4

#include <corewar/corewar.h>

void debug_and_pause(output_op_t *op, program_memory_t *mem);
void dump_memory(unsigned char *bytes, size_t len);
void diff_memory(unsigned char *old, unsigned char *new, size_t len);
void debug_memory(output_op_t *op, program_memory_t *mem);

#endif /* C0269E7C_BDF2_4097_B8CC_E878150123D4 */
