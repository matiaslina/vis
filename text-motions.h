#ifndef TEXT_MOTIONS_H
#define TEXT_MOTIONS_H

#include <stddef.h>
#include "text.h"

size_t text_find_char_next(Text*, size_t pos, const char *s, size_t len);
size_t text_find_char_prev(Text*, size_t pos, const char *s, size_t len);

/*        begin            finish
 *        v                v
 *  \n[\r]      I am a line!       \n[\r]
 *              ^                  ^
 *              start              end
 */
size_t text_line_begin(Text*, size_t pos);
size_t text_line_start(Text*, size_t pos);
size_t text_line_finish(Text*, size_t pos);
size_t text_line_end(Text*, size_t pos);
/*
 * A word consists of a sequence of non-blank characters, separated with white space.
 * TODO?: An empty line is also considered to be a word. This is equivalant to a WORD
 * in vim terminology.
 */
size_t text_word_end_next(Text*, size_t pos);
size_t text_word_end_prev(Text*, size_t pos);
size_t text_word_start_next(Text*, size_t pos);
size_t text_word_start_prev(Text*, size_t pos);
/* 
 * These are variants of the above with the additional possibility to implement
 * a custom word detection logic. Can be used to implment the equivalent of a what
 * vim reconizes as a word (lowercase).
 */
size_t text_word_boundry_end_next(Text*, size_t pos, int (*isboundry)(int));
size_t text_word_boundry_end_prev(Text*, size_t pos, int (*isboundry)(int));
size_t text_word_boundry_start_next(Text*, size_t pos, int (*isboundry)(int));
size_t text_word_boundry_start_prev(Text*, size_t pos, int (*isboundry)(int));
/* TODO: implement the following semantics
 * A sentence is defined as ending at a '.', '!' or '?' followed by either the
 * end of a line, or by a space or tab.  Any number of closing ')', ']', '"'
 * and ''' characters may appear after the '.', '!' or '?' before the spaces,
 * tabs or end of line.  A paragraph and section boundary is also a sentence
 * boundary.
 */
size_t text_sentence_next(Text*, size_t pos);
size_t text_sentence_prev(Text*, size_t pos);
/* TODO: implement the following semantics
 * A paragraph begins after each empty line. A section boundary is also a 
 * paragraph boundary. Note that a blank line (only containing white space)
 * is NOT a paragraph boundary.
 */
size_t text_paragraph_next(Text*, size_t pos);
size_t text_paragraph_prev(Text*, size_t pos);
/* A section begins after a form-feed in the first column. 
size_t text_section_next(Text*, size_t pos);
size_t text_section_prev(Text*, size_t pos);
*/
/* search coresponding '(', ')', '{', '}', '[', ']', '>', '<', '"', ''' */
size_t text_bracket_match(Text*, size_t pos);

#endif