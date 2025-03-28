# 🕹️ GameBox-Hub | 多语言小游戏集合 🚀

**欢迎来到代码游乐场！** 这里收藏了用不同语言编写的经典小游戏，C语言打头阵，Python正在路上，未来还有更多惊喜！🎮 随时来玩，也欢迎贡献你的创意！

（关于游戏大厅设计狮正在疯狂赶工，先想象一下复古街机厅的样子吧！）

---

## 📦 已上架游戏

### 1. 2048 终端版（C语言） 
- **玩法**：滑动数字合成2048，挑战你的策略极限！  
- **特色**：  
  
  - 🖥️ 纯终端运行，极客范儿拉满  
  - ⚡ 丝滑移动算法，拒绝卡顿  
  - 🎲 玄学概率生成（开发者：2和4的权重绝对没做手脚！）  
- **快速开玩**：  
  ```bash
  cd 2048-terminal
  make && ./game

### 🚧 施工中游戏
| 游戏名       | 语言   | 状态     | 招募需求                |
|--------------|--------|----------|-------------------------|
| 贪吃蛇       | Python | 开发中   | 需要会扭动的ASCII艺术   |
| 俄罗斯方块   | C      | 设计阶段 | 寻找方块旋转算法大师    |
| 扫雷         | Rust   | 构思中   | 需要爆炸特效设计师      |

---

## 🛠️ 如何贡献

**欢迎成为游戏厅管理员！** 你可以：  
- 💡 **提议新游戏**：在Issues开脑洞  
- 🎨 **美化界面**：让终端游戏也能有炫酷特效  
- 🐛 **捉虫小分队**：专治各种程序不服  
- 📚 **写文档**：把"按任意键继续"翻译成火星文  

**贡献指南**：  
1. Fork本仓库  
2. 为你的游戏创建独立目录（如 `snake-python/`）  
3. 确保包含：  
   - 可执行文件或明确的使用说明  
   - 一个卖萌的README（参考2048的文档）  
   - 开源许可证（建议MIT）  
4. 发起Pull Request，并附上游戏截图  

---

## 🔧 通用安装指南

### C语言游戏  
```bash
# 进入游戏目录后
make       # 使用Makefile编译
./game     # 开玩！
```

### Python游戏  
```bash
pip install -r requirements.txt  # 如有依赖
python game.py
```

---

## 🌟 未来计划
- **成就系统**：收集"肝到凌晨三点"徽章  
- **跨语言对战**：让C语言贪吃蛇大战Python版  
- **全球排行榜**：你的分数将接受全宇宙玩家的挑战  

---

## 📜 开源协议
MIT License —— 你可以：  
- 随意魔改代码，甚至把2048改成4096  
- 打包卖给学生党，但别忘了说是本仓库教的  
- 唯一禁止事项：声称这些游戏是女朋友写的  

**温馨提示**：如果代码跑不起来，试试对着屏幕唱《好运来》🎵  
（开发者亲测有效，但仅限农历初一和十五）