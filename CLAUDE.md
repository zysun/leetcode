# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 项目概述

这是一个 LeetCode 刷题仓库，使用 C++ 讲解算法套路，每一类算法配合教学文档和多道题目实战。文档使用中文撰写。

## 常用命令

每个 `.cpp` 文件是独立的，包含 `main()` 和测试用例，可直接编译运行：

```bash
g++ -std=c++17 -o /tmp/a.out sliding_window/cpp/643_子数组最大平均数I.cpp && /tmp/a.out
```

## 目录结构

```
sliding_window/
  滑动窗口算法.md          # 算法讲解文档（核心思想、模板、常见错误、题目实战）
  cpp/
    643_*.cpp              # 每道题的独立解法 + main() 含测试用例
    1423_*.cpp
    ...
```

后续新增算法类别时，会在根目录创建对应的新目录（如 `dp/`, `binary_search/`），结构与 `sliding_window/` 一致。

## C++ 文件约定

- `using namespace std;` 全局使用
- 每道题一个 `class Solution` + 独立 `main()` 函数
- `main()` 中包含多个测试用例，输出实际结果和期望结果
- 文件头注释写有题号、思路和复杂度分析
- 编译标准：C++17
