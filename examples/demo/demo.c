/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Bekir Kağan Karaahmetoğlu <kagankaraahmetoglu@hotmail.com>
 */

#include <lexan/lex_logger.h>

int main() {
    lex_logger_init();
    LEX_LOG_DEBUG("%s\n", "This is a debug log.");
    LEX_LOG_INFO("%s\n", "This is an info log.");
    LEX_LOG_WARN("%s\n", "This is a warn log.");
    LEX_LOG_ERROR("%s\n", "This is an error log.");
    LEX_LOG_FATAL("%s\n", "This is a fatal log.");
    lex_logger_deinit();
    return 0;
}
