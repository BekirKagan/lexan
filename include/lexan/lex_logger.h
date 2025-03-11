/*
 *   lex_logger.h - A lightweight C logging library with color-coded output and simple macros.
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
