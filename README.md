## **论文分类**

#### **1. Graphs Shorest Paths Algorithms**

* Fully Dynamic Shortest-Path Distance Query Acceleration on Massive Networks[C]. Takanori Hayashiy, Takuya Akibaz, Ken-ichi Kawarabayashi. CIKM'16 (CCF-B)，该文是目前最新的针对大规模图数据（billion-scale networks）的动态最短路径算法。任意两个节点之间的距离度量时图论中最基础的研究问题，它是其它经典度量的基础，其它经典度量包括：相似性、中心性等。2-hop标签方法是广为人知的最快的点到点距离度量算法，但是它仅仅针对million-scale图。在这篇文章中，作者提出了第一个能够处理billion-scale规模图数据的最快速精确最短路径算法。该方法结合了BFS和离线索引技术。其中BFS方法用到了启发式探索方法。接着构建了并行最短路径树。
* Dynamic and Historical Shortest-Path Distance Queries on Large Evolving Networks by Pruned Landmark Labeling. WWW'14 （CCF-C）
* Fast fully dynamic landmark-based estimation of shortest path distances in very large graphs. CIKM'11 （CCF-B）


#### **2. Graph Analysis and Prrocessing Platforms**

* Big Graphs Anslytics Platform [Book]. Da Ya and Yuanyuan Tian. 该书详细的介绍了当前存在的针对大规模图数据的分析平台，设计与实现技术。 
* Systems For Big Graph Analytics [Book]. Yuanyuan Tian. 与上篇文章作者相同，详细地讲述了当前存在的图分析平台的设计与实现技术。

## **使用到的Library**

目前成功编译的Library有：
* Boost https://www.boost.org/
* Dlib http://dlib.net/   安装Dlib之前首先应该编译Boost
* TensorFlow  https://www.tensorflow.org/
* igraph http://igraph.org/

