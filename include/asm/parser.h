/*
** EPITECH PROJECT, 2021
** parser
** File description:
** Source code
*/

#ifndef DC348E51_57D5_4ED5_9CDF_0EBCA8AD3A30
#define DC348E51_57D5_4ED5_9CDF_0EBCA8AD3A30

#include <corewar/corewar.h>

typedef struct label {
    struct label *prev;
    struct label *next;
    char *label;
    struct instruction *target;
} label_t;

typedef struct labels_ll {
    struct label *head;
    struct label *tail;
    int size;
} labels_ll_t;

///
/// A parsed instruction
///
typedef struct instruction {
    int id;
    struct instruction *prev;
    struct instruction *next;
    char *position;
    byte_t bytecode;
    arg_t args[4];
    char *label;
} instruction_t;

typedef struct instructions_ll {
    struct instruction *head;
    struct instruction *tail;
    int size;
} instructions_ll_t;

typedef struct parsed_program {
    char *name;
    char *desc;
    instructions_ll_t instructions;
    labels_ll_t labels;
} parsed_program_t;

enum parser_error_code {
    NO_ERROR,
    EXPECT_TOKEN,
    INVALID_TOKEN,
    ALLOC_FAILED
};

typedef struct parser_error {
    char *pos;
    enum parser_error_code code;
    char *message;
} parser_error_t;

typedef struct parser {
    char *start;
    char *pos;
    char *filename;
    parsed_program_t program;
    parser_error_t errors[10];
} parser_t;

int parse_program(parser_t *parser);

///
/// Add an error to the parser error stack.
/// Returns a negative number (subzero).
///
int parser_error(parser_t *parser, enum parser_error_code code, char *message);

///
/// If one or more space/tab is found in current position, consume it.
/// Returns the number of whitespace chars skipped
///
int consume_whitespaces(parser_t *parser);

///
/// If one or more newlines is found in current position, consume it.
/// Returns the number of lines consumed (not the number of chars!)
///
int consume_newlines(parser_t *parser);

///
/// If one comma is found in current position, consume it.
/// Returns the number of commas consumed, 0 or 1.
///
int consume_comma(parser_t *parser);

///
/// Consume an instruction menmonic.
/// Returns the corresponding bytecode.
///
byte_t consume_instruction_mnemo(parser_t *parser);

///
/// Consume an argument label.
/// Format: `:label`.
/// Set output_label pointer to the position (address) of the label name.
/// Returns the length of the label name.
/// If no label is found, returns 0.
/// On parse error, returns an negative error code and append an error
/// to the parser errors.
///
int consume_arg_label(char **output_label, parser_t *parser);

///
/// Consume a label.
/// Format: `label:`.
/// Set output_label pointer to the position (address) of the label name.
/// Returns the length of the label name.
/// If no label is found, returns 0.
///
int consume_label(char **output_label, parser_t *parser);

///
/// Consume one or more decimal digits.
/// Set the value of output_value to the value of the number consumed.
/// Returns the number of digits consumed, or 0 if no number is found.
///
int consume_number(int *output_value, parser_t *parser);

///
/// Read the input file, then fill the output buffer and the output parser.
///
int init_parser_from_file(char *output_buffer, parser_t *output_parser,
    char *file);

int init_parser(parser_t *output_parser, char *file, char *input);

int read_file(char *output_buffer, char *file);

#endif /* DC348E51_57D5_4ED5_9CDF_0EBCA8AD3A30 */
