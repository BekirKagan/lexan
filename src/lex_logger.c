/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Bekir Kağan Karaahmetoğlu <kagankaraahmetoglu@hotmail.com>
 */

#include <lexan/lex_logger.h>
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

void lex_logger_log(LEX_LogLevel lvl, const char* fmt, ...) {
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

void lex_logger_init() {
    DWORD mode = 0;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(handle, &mode);
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(handle, mode);
}

void lex_logger_deinit() {
    DWORD mode = 0;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(handle, &mode);
    mode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(handle, mode);
}
#else
void lex_logger_init() {
    LEX_LOG_INFO("%s\n", "The lex_logger_init() function is only needed on Windows.");
}
void lex_logger_deinit() {
    LEX_LOG_INFO("%s\n", "The lex_logger_deinit() function is only needed on Windows.");
}
#endif // _WIN32
