#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd; /* file descriptor */
	ssize_t w; /* number of bytes written */
	size_t len = 0; /* length of text_content */

	if (filename == NULL) /* check if filename is NULL */
		return (-1);

	if (text_content != NULL) /* check if text_content is not NULL */
	{
		while (text_content[len]) /* calculate the length of text_content */
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND); /* open file for writing and appending */
	if (fd == -1) /* check if file opening failed */
		return (-1);

	w = write(fd, text_content, len); /* write text_content to the end of file */

	if (w == -1) /* check if file writing failed */
	{
		close(fd); /* close file */
		return (-1);
	}

	close(fd); /* close file */

	return (1); /* return success */
}
