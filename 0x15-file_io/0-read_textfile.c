#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	int fd;
	ssize_t w;
	ssize_t r;

	if (filename == NULL) /* check if filename is NULL */
		return (0);

	fd = open(filename, O_RDONLY); /* open file for reading */
	if (fd == -1) /* check if file opening failed */
		return (0);

	buf = malloc(sizeof(char) * letters); /* allocate memory for buffer */
	if (buf == NULL) /* check if memory allocation failed */
	{
		close(fd); /* close file */
		return (0);
	}

	r = read(fd, buf, letters); /* read file into buffer */
	if (r == -1) /* check if file reading failed */
	{
		free(buf); /* free buffer */
		close(fd); /* close file */
		return (0);
	}

	w = write(STDOUT_FILENO, buf, r); /* write buffer to standard output */

	free(buf); /* free buffer */
	close(fd); /* close file */
	return (w); /* return number of bytes written */
}
