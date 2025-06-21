# lexan

**lexan** is a lightweight C logging library that provides easy-to-use logging macros for different log levels, including **debug, info, warn, error,** and **fatal**. Logs are printed to **stdout** with colors for better readability.

## Features
- Simple **logging macros**: `LEX_LOG_DEBUG`, `LEX_LOG_INFO`, `LEX_LOG_WARN`, `LEX_LOG_ERROR`, `LEX_LOG_FATAL`
- **Color-coded output** for better log visibility
- Lightweight and **dependency-free**
- Built as a **static library**
- **CMake** support for easy integration

## Installation

### Clone the repository:
To get started with **lexan**, clone the repository:

```bash
git clone https://github.com/BekirKagan/lexan.git
```

### Build using CMake:

This project uses **CMake** to build. To build it as a static library, follow these steps:

```bash
cd lexan
cmake -S . -B build -G Ninja -D CMAKE_EXPORT_COMPILE_COMMANDS=1 -D CMAKE_BUILD_TYPE=Release -D LEX_BUILD_EXAMPLES=1
cmake --build build
```

Once the build process is complete, the static library will be available for use.

### Usage:

1.  Include the header files from the **`include/lexan`** folder in your project.
2.  Link the **`lexan`** static library during your project’s build.
3.  Use the logging macros in your code.

For more detailed examples, check out the **examples** folder.

## Example:

The **examples** folder contains sample implementations demonstrating how to integrate **lexan** into your project.

### Example Usage in Code:

```c
#include <lexan/lex_logger.h>

int main() {
    lex_logger_init(); // Required only on Windows.
    LEX_LOG_DEBUG("%s\n", "This is a debug log.");
    LEX_LOG_INFO("%s\n", "This is an info log.");
    LEX_LOG_WARN("%s\n", "This is a warn log.");
    LEX_LOG_ERROR("%s\n", "This is an error log.");
    LEX_LOG_FATAL("%s\n", "This is a fatal log.");
    lex_logger_deinit(); // Required only on Windows.
    return 0;
}
```
Check the **examples** folder for more complex demonstrations.

## Contributing

We welcome contributions to **lexan**! If you'd like to improve or extend the functionality of the library, feel free to fork the repository and submit a pull request. Please follow these guidelines:

-   **Bug reports** or **feature requests** should be opened as GitHub issues.
-   Contributions should be made via pull requests.
-   Please include relevant tests or examples where applicable.

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for full details.

## Contact

For questions, suggestions, or collaborations, feel free to reach out:

- Email: [kagankaraahmetoglu@hotmail.com](mailto:kagankaraahmetoglu@hotmail.com)
- Instagram: [@bekirkagankaraahmetoglu](https://www.instagram.com/bekirkagankaraahmetoglu)

---
Thank you for using **lexan**!
