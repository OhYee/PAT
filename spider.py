import requests
import re
import json

folderPath = "basic"
level = "乙级"

url = input("input the url of the problem\n")
apiUrl = url.replace(".cn/problem-sets", ".cn/api/problem-sets")
response = requests.get(apiUrl)
html = response.text
data = json.loads(html)['problemSetProblem']


ID = data['label']
title = data['title']
content = data['content']

title = re.findall(r"^(.*?) \([0-9]+\)$", title)[0]
content = re.sub(r"(?<=\*\*输.样例：\*\*)\n\n\s+(.*)\n",
                 r"\n<samp>\1</samp>", content, flags=re.M)
cpp = ""
python = ""
java = ""

filename = "./" + folderPath + "/" + ID + "."
with open(filename + "cpp", "r") as f:
    cpp = f.read()
with open(filename + "py", "r") as f:
    python = f.read()
with open(filename + "java", "r") as f:
    java = f.read()

template = '''# 题目
[原题链接]({url})
<blockquote>
{content}
</blockquote>

# 解析


# 代码
## C++解法
```cpp
{cpp}
```

## Python解法
```Python
{python}
```

## Java解法
```java
{java}
```'''

outputTitle = "PAT" + level + " " + ID + "." + title
outputUrl = 'pat/' + folderPath + "/" + ID
outputContent = template.format(url=url, cpp=cpp, java=java,
                                python=python, content=content)
outputTag = "PAT,PAT" + level + ",题解"

outputContent = outputContent.replace("\\", "\\\\")
outputContent = outputContent.replace("\n", "\\n")
outputContent = outputContent.replace("\"", "\\\"")


output = 'vue.title.value="{outputTitle}";vue.url.value="{outputUrl}";vue.tags.value="{outputTag}";vue.raw="{outputContent}"'
output = output.format(outputTitle=outputTitle, outputUrl=outputUrl,
                       outputContent=outputContent, outputTag=outputTag)

with open("in.txt", "w", encoding="utf-8") as f:
    f.write(output)
