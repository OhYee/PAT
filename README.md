# PAT(Programming Ability Test)
[Site](https://www.patest.cn/)
[Problem Sets](https://pintia.cn/problem-sets)
[more Answer](https://www.oyohyee.com/tag/pat/)

# Developing Environment
Editor: [Visual Studio Code](https://github.com/Microsoft/vscode)

One key(`F5`) compile and run C/C++、Python、Java
Keybinding:
```json
[
    {"key": "f5","command": "workbench.action.tasks.runTask","args": "C/C++" },
    { "key": "f5","command": "workbench.action.tasks.runTask","args":"Python", "when":"resourceExtname == .py"},
    { "key": "f5","command": "workbench.action.tasks.runTask","args":"Java", "when":"resourceExtname == .java"},
    
    { "key": "f7","command": "workbench.action.tasks.runTask"}
]
```

tasks:
```json
{
    "version": "0.1.0",
    "tasks": [
        {
            "taskName": "C/C++",
            "command": "",
            "isShellCommand": false,
            "showOutput": "always",
            "echoCommand": false,
            "suppressTaskName": false,
            "args": [
                "g++ -g -Wall \"${file}\" -o \"${file}.exe\" -std=c++14 -O2 && \"${file}.exe\" <in.txt && del /Q \"${file}.exe\""
            ],
            "problemMatcher": {
                "owner": "cpp",
                "fileLocation": [
                    "relative",
                    "/"
                ],
                "pattern": {
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            }
        },
        {
            "taskName": "Python",
            "command": "",
            "isShellCommand": true,
            "showOutput": "always",
            "echoCommand": false,
            "suppressTaskName": false,
            "args": [
                "python \"${file}\"<in.txt",
            ],
            "problemMatcher": []
        },
        {
            "taskName": "Java",
            "command": "",
            "isShellCommand": true,
            "showOutput": "always",
            "echoCommand": false,
            "suppressTaskName": false,
            "args": [
                "javac \"${file}\" && java -classpath \"${fileDirname}\" Main <in.txt && del /Q \"${fileDirname}\\Main.class\""
            ],
            "problemMatcher": {
                "owner": "java",
                "fileLocation": [
                    "relative",
                    "/"
                ],
                "pattern": {
                    "regexp": "^(.*):(\\d+):\\s+(warning|error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "severity": 3,
                    "message": 4
                }
            }
        }
    ]
}
```