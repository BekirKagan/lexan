#include <denovo/dn_logger.h>

int main() {
    dn_logger_init();
    DN_LOG_DEBUG("%s\n", "This is a debug log.");
    DN_LOG_INFO("%s\n", "This is an info log.");
    DN_LOG_WARN("%s\n", "This is a warn log.");
    DN_LOG_ERROR("%s\n", "This is an error log.");
    DN_LOG_FATAL("%s\n", "This is a fatal log.");
    dn_logger_deinit();
    return 0;
}
