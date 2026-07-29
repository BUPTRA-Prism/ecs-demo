function(enable_compiler_warnings target)

    target_compile_options(
        ${target}
        PRIVATE

        -Wall
        -Wextra
        -Wpedantic
    )

endfunction()