/*
 *   dn_logger.c - A lightweight C logging library with color-coded output and simple macros.
 *   Copyright (C) 2025 Bekir Kağan Karaahmetoğlu <kagankaraahmetoglu@hotmail.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <denovo/dn_logger.h>
#include <stdarg.h>
#include <stdio.h>

#define RESET_SEQ "\x1b[0m"

static const char* const LEVELS[5] = {
    "[DEBUG]: ",
    "[INFO]: ",
    "[WARN]: ",
    "[ERROR]: ",
    "[FATAL]: ",
};

static const char* const COLORS[5] = {
    "\x1b[35m",   // DEBUG
    "\x1b[32m",   // INFO
    "\x1b[33m",   // WARN
    "\x1b[31m",   // ERROR
    "\x1b[1;31m", // FATAL
};

void dn_logger_log(DN_LogLevel lvl, const char* fmt, ...) {
    const char* color = COLORS[lvl];
    const char* level = LEVELS[lvl];

    char buffer[512] = {0};
    char output[512] = {0};

    va_list args;
    va_start(args, fmt);
    vsnprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, fmt, args);
    va_end(args);

    sprintf_s(output, sizeof(output), "%s%s%s%s", color, level, buffer, RESET_SEQ);
    printf_s("%s", output);
}

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void dn_logger_init() {
    DWORD mode = 0;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(handle, &mode);
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(handle, mode);
}

void dn_logger_deinit() {
    DWORD mode = 0;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(handle, &mode);
    mode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(handle, mode);
}
#else
void dn_logger_init() {
    DN_LOG_INFO("%s\n", "The dn_logger_init() function is only needed on Windows.");
}
void dn_logger_deinit() {
    DN_LOG_INFO("%s\n", "The dn_logger_deinit() function is only needed on Windows.");
}
#endif // _WIN32
