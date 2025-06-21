/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Bekir Kağan Karaahmetoğlu <kagankaraahmetoglu@hotmail.com>
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef _DEBUG
#define LEX_LOG_DEBUG(fmt, ...) lex_logger_log(LEX_LOG_LEVEL_DEBUG, fmt, ##__VA_ARGS__)
#else
#define LEX_LOG_DEBUG(fmt, ...)
#endif // _DEBUG

#define LEX_LOG_INFO(fmt, ...) lex_logger_log(LEX_LOG_LEVEL_INFO, fmt, ##__VA_ARGS__)
#define LEX_LOG_WARN(fmt, ...) lex_logger_log(LEX_LOG_LEVEL_WARN, fmt, ##__VA_ARGS__)
#define LEX_LOG_ERROR(fmt, ...) lex_logger_log(LEX_LOG_LEVEL_ERROR, fmt, ##__VA_ARGS__)
#define LEX_LOG_FATAL(fmt, ...) lex_logger_log(LEX_LOG_LEVEL_FATAL, fmt, ##__VA_ARGS__)

typedef enum LEX_LogLevel {
    LEX_LOG_LEVEL_DEBUG,
    LEX_LOG_LEVEL_INFO,
    LEX_LOG_LEVEL_WARN,
    LEX_LOG_LEVEL_ERROR,
    LEX_LOG_LEVEL_FATAL,
} LEX_LogLevel;

void lex_logger_init();
void lex_logger_deinit();
void lex_logger_log(LEX_LogLevel lvl, const char* fmt, ...);

#ifdef __cplusplus
}
#endif // __cplusplus
