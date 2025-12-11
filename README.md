# EnseaSH — Micro Shell Project

## 📜 Description

EnseaSH is a lightweight micro shell developed as a synthesis practical work (“TP de Synthèse”) for the 2nd year of the Computer Science Major at ENSEA.[file:1]  
It explores core system programming concepts such as process creation, signal handling, file descriptor management, and execution time measurement through a progressive set of shell features.[file:1]

## 🎯 Project Goals

- Understand how a shell interacts with the operating system using system calls such as `fork`, `exec`, and `wait`.[file:1]  
- Practice process management, signals, and file descriptor manipulation (redirections, pipes, background jobs).[file:1]  
- Measure and display execution time using `clock_gettime` to analyze command performance.[file:1]  

## 🧰 Technical Constraints

- 🚫 **No `printf`**: Standard I/O calls like `printf` are avoided; low-level I/O with `write` is preferred.[file:1]  
- 🚫 **No `system()`**: The `system` function is forbidden; only the `exec` family is used to run external programs.[file:1]  
- ✅ **Code quality**: No “magic numbers”, clear English identifiers, and modular, well-structured functions.[file:1]  
- 🔤 **String handling**: Use `string.h` and safer `strn*` functions for manipulating character buffers.[file:1]  

## 🏫 Course Information

- Course: 2nd Year — Computer Science Major at ENSEA.[file:1]  
- Practical work: “Ensea in the Shell” (EnseaSH).[file:1]  

## ✍️ Authors

- Aoudia Yanis  
- Ziane Ismael


## Features Status

| Question | Tasks to Implement                                                                 | Implemented |
|----------|------------------------------------------------------------------------------------|-------------|
| Q1       | Display welcome message and show simple `enseash %` prompt                        | Yes         |
| Q2       | Read user command input, execute simple command (no args), then return to prompt  | Yes         |
| Q3       | Exit on `exit` command and on Ctrl+D (EOF)                                        | Yes         |
| Q4       | Capture exit code or signal from child and display it in prompt `[exit:X]` / `[sign:X]` | Yes  |
| Q5       | Measure execution time with `clock_gettime` and display time in prompt `[Xms]`    | Yes         |
| Q6       | Parse command with arguments (spaces) and pass full `argv[]` to `execvp`          | No          |
| Q7       | Parse `<` and `>` redirections, open files, and use dup2 for stdin/stdout before exec | No      |
| Q8       | Parse pipe operator, create a pipe, fork twice, and connect processes with dup2 | No       |
| Q9       | Handle `&` background jobs with non-blocking wait and display job completion      | No          |
