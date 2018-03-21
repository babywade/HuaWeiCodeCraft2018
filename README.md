# HuaWeiCodeCraft2018
华为软件精英挑战赛2018

***

# 机器学习

### 章节目录

* 1.引言；棋盘问题建模
* 2.概念学习和一般到特殊序
* 3.决策树学习
* 4.人工神经网络
* 5.评估假设
* 6.贝叶斯学习
* 7.计算学习理论
* 8.基于实例的学习
* 9.遗传算法
* 10.学习规则集合
* 11.分析学习
* 12.归纳和分析学习的结合
* 13.增强学习

### 训练经验

类型：
* 直接(各种棋盘状态，相应正确走子)
* 间接(走子序列&最终结局)，涉及每一步的信用分配问题

学习器如何控制训练样例序列
* 与施教者即训练样本的关系

训练样本能多好地表示实例分布
* 很多的机器学习理论都是基于训练样例与测试样例分布一致这一假设

### 西洋跳棋学习问题

* 任务T；性能标准P；训练经验E
* 需要选择: 学习的知识的类型；对于目标知识的表示；一种学习机制
* 从一个大的合法走子空间中选择最佳走子
* 学习function：ChooseMove；问题简化为学习像ChooseMove这样某个特定的目标函数(TargetFunction)；所以TargetFunction的选择很重要
* 另外一个可供选择的目标函数是一个评估函数，它为任何给定棋局赋予一个数字评分
V：B->R表示V把任何合法的棋局从集合B映射到某个实数值
* 定义如下：b最终胜局，V(b)=100;
b最终负，V(b)=-100;
b最终和局,V(b)=0;
b不是最终棋局，V(b)=b(b').
然而这个定义对于某一种中间状态需要决定其后的所有路线，因此是不可操作的定义
* 任务被简化为一个理想目标函数V的可操作描述，学习这个目标函数的过程常被称为函数逼近

简单选择一个线性目标函数
* 六个参数，黑子，红子，黑王，红王，被威胁黑子数量，被威胁红子数量
* 跳棋程序的部分设计为：
T:下西洋跳棋；P:世界锦标赛上击败对手的百分比；
E:和自己对弈;V：Board->R；目标函数表示：线性加权
* 需要一系列训练样例，每一个训练样例描述了特定的棋盘状态b和训练值v(b)
* 学习器可以得到的训练信息仅是对弈最后的胜负；同时，我们需要训练样例为每个棋盘状态赋予一个分值。
难点在于给每个棋盘的中间状态赋予一个分值。
* 一个简单的方法取得了良好的效果：用后继棋局的近似值来估计训练值；事实上，这种基于对后继棋局进行估计的迭代估计训练值的方法，已被证明可以近乎完美地收敛到估计值。
* 定义最佳拟合的含义：使训练值和假设V预测出的值间的误差平方和E最小
* 已经知道一些算法可以得到线性函数的权使此定义的E最小化，这里需要一个算法使得它可以再有了新的训练样例时进一步精化权值，并且它对估计的训练数据中的差错有好的健壮性，LMS训练方法。least mean squares
* 这个算法可被看作对可能的假设空间进行随机的梯度下降搜索。。。
* 学习程序的最终设计
实验生成器；执行系统(输入新问题，输出解答路线)；鉴定器(历史记录作为输入，输出训练样例目标函数Vtrain;估计法则)；泛化器(输入训练样例Vtrain，输出权值w)

### 第二章(概念学习)

* 概念学习任务：已知实例集X；假设集H；目标概念c；训练样集D；求解：H中的一般假设h，使得X中任意x，h(x)=c(x)
* 通常可以用序偶来描述训练样例；归纳学习假设，假定对于未见实例最好的假设就是与训练数据最佳拟合的假设，这是归纳学习的一个基本假定。
* 归纳学习假设：任一假设如果在足够大的训练样集中很好地逼近目标函数，它也能在未见实例中很好地逼近目标函数。
* 引起我们兴趣的算法应能有效地搜索非常大的或无限大的假设空间，以找到最佳拟合训练数据的假设。
* 一般到特殊的关系，即集合的包含与被包含关系；偏序关系，两个集合间不存在包含与被包含关系但有重合。偏序关系对任意概念学习提供了一种有效的结构
* FIND-S:寻找极大特殊假设；
    1. 将h初始化为H中最特殊假设
    2. 对每个正例x；h中的每个属性约束a，若x满足a则不做任何处理，否则将h中a替换为x满足的另一个更一般约束；
    3. 输出假设h
* FIND-S算法保证输出为H中与正例一致的最特殊的假设
，只要正确的目标概念包含在H中并且训练数据都是正确的，最终的假设也与所有反例一致。
* 变型空间与候选消除(输出的时与训练样例一致的所有假设的集合)；
    1. 应用有化学质谱分析，学习启发式搜索的控制规则
    2. 候选消除与FIND-S在训练数据含有噪声时性能较差

### 第三章——决策树

* 应用最广的归纳推理算法之一，它是一种逼近离散值函数的方法，对噪声数据有很好的健壮性且能够学习析取表达式。归纳偏置是优先选择较小的树。
* 学习得到的决策树可被表示为多个if-then规则，已被成功运用到学习医疗诊断以及学习评估贷款申请的信用风险。
* 决策树通过把实例从根节点排列(sort)到某个叶子节点来分类实例；每一个节点说明了对实例的某个属性(attribute)的测试，每一个后继分支对应于该属性的一个可能值
* 决策树适用的问题：
    1. 实例是由attribute-value pair表示的
    2. 目标函数具有离散的输出值
    3. 可能需要析取的描述
    4. 训练数据可以包含错误
    5. 训练数据可以包含缺少属性值的实例
* 决策树的应用场景(分类问题b):
    1. 根据疾病分类患者
    2. 根据起因分类设备故障
    3. 根据拖欠支付的可能性分类贷款申请
* ID3算法与C4.5算法；采用自顶向下的贪心搜索遍历可能的决策树空间；首先选取根节点属性
* 如何选取每个节点要测试的属性，定义一个统计性，称为"信息增益"即信息熵。筛选出信息熵最大的一个候选属性作为根节点属性。
* ID3算法搜索的假设空间是可能的决策树的集合；其以一种从简单到复杂的爬山算法遍历这个假设空间；引导这个爬山搜索的评估函数是信息增益度量即信息熵。最终搜索到一个正确分类训练数据的决策树。
* ID3避免了搜索不完整假设空间即避免了搜索不完整假设空间的一个主要风险：可能不包含目标函数；ID3仅维护单一的当前假设；搜索中不进行回溯，容易收敛到局部最优；搜索的每一步都使用了当前的所有训练样例，以统计为基础决定如何去精化假设，因此大大降低了对个别训练样例错误的敏感性。
* ID3使用的选择属性的启发式规则和特定训练样例之间存在着微妙的相互作用
* 近似的ID3算法归纳偏置：较短的树比较长的树优先；广度优先搜索类似ID3(BFS-ID3)；事实上，ID3使用信息熵启发和"爬山"策略包含了比BFS-ID3更复杂的偏置。
* ID3的归纳偏置来自它的搜索策略，候选消除算法的归纳偏置来自它对于搜索空间的定义；ID3的偏置被称为优选偏置或搜索偏置，候选消除偏置被称为限定偏置或语言偏置。
* 使用线性函数表示评估函数的决定就引入了限定偏置；
选择了有一个特定的参数调整算法就引入了优选偏置。

### 第四章——人工神经网络ANN

* 提供了一种普遍且实用的方法从样例中学习值为实数、离散值或向量的函数，已经应用到视觉场景分析、语音识别以及机器人控制等。
* 对于某些类型的问题，如学习解释复杂的现实世界中的传感器数据，神经网络是目前知道的最有效的学习方法。
* 反向传播算法:
    1. 学习识别手写字符
    2. 学习识别口语
    3. 学习识别人脸
* ANN每个单元输出单一的不变值，而生物神经元输出的是复杂的时序脉冲。
* 人工神经网络的研究者分为两个团体：一个团体的目标是研究和模拟生物学习过程；另一个团体的目标是获得高效的机器学习算法，不管其是否反映了生物学习过程。
* 适合神经网络学习的问题
    * 实例是用很多"attribute-value"pair表示
    * 目标函数的输出可能是离散值、实数值或由若干实数属性或离散属性组成的向量
    * 训练数据可能包含错误
    * 可容忍长时间的训练
    * 可能需要快速求出目标函数值
    * 人类能否理解学到的目标函数是不重要的
