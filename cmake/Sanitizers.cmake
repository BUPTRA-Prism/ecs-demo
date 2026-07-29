function(enable_sanitizers target)

    # ===== 编译阶段 =====
    target_compile_options(
        ${target}
        PRIVATE

        # ===== Debug 模式添加如下选项 =====
        $<$<CONFIG:Debug>:-fsanitize=address>       # 地址相关
        $<$<CONFIG:Debug>:-fsanitize=undefined>     # UB行为
        $<$<CONFIG:Debug>:-fno-omit-frame-pointer>  # 保留调用栈
    )

    # ===== 链接阶段 =====
    target_link_options(
        ${target}
        PRIVATE

        # ===== Debug 模式添加如下选项 =====
        $<$<CONFIG:Debug>:-fsanitize=address>       # 地址相关
        $<$<CONFIG:Debug>:-fsanitize=undefined>     # UB行为
    )

endfunction()