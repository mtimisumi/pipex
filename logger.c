#include "pipex.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void logger(const char *format, ...)
{
    static int is_first_log = 1; // Static variable to track the first log call
    int log_fd;

    if (is_first_log)
    {
        // Clear the log file on the first log
        log_fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        is_first_log = 0;
    }
    else
    {
        // Append to the log file for subsequent logs
        log_fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    }

    if (log_fd == -1)
    {
        perror("Failed to open log file");
        return;
    }

    va_list args;
    va_start(args, format);

    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), format, args);
    write(log_fd, buffer, strlen(buffer));
    write(log_fd, "\n", 1);

    va_end(args);
    close(log_fd);
}

int check_file_permissions(const char *path, int flags)
{
    if (access(path, F_OK) == -1)
    {
        perror("File does not exist");
        return ERR_NO_FILE;
    }

    if ((flags & HAS_READ) && access(path, R_OK) == -1)
    {
        perror("No read permission");
        return ERR_NO_PERM;
    }

    if ((flags & HAS_WRITE) && access(path, W_OK) == -1)
    {
        perror("No write permission");
        return ERR_NO_PERM;
    }

    if ((flags & HAS_EXEC) && access(path, X_OK) == -1)
    {
        perror("No execute permission");
        return ERR_NO_PERM;
    }

    return SUCCESS; // File exists and has the required permissions
}