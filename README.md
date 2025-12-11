# TP-Programmation-Syst-me-MicroShell
Objectifs : Réaliser un micro shell, affichant les codes de sortie et les temps d’exécution des programmes lancés.


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
