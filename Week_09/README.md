# 高级动态规划

动态规划讲得最好的还是东哥，他的gitbook上面归纳了大量的动态规划问题的套路。
包含了最长递增子序列、最大子数组、子集背包问题、完全背包问题、编辑距离、高楼扔鸡蛋
戳气球、博弈问题、正则表达、四键键盘、KMP字符匹配算法、股票买卖、打家劫舍

# 字符串算法

字符串是编程中非常重要的一个课题，在web开发中，大量的URL需要使用字符串进行处理。掌握
好字符串算法是优秀程序员的必修课。课程中提到了几个高级的字符串匹配算法

## RK算法

选择一个合适的哈希函数，效率需要足够高。同时对两个字符串进行哈希值计算。如果二者的哈希值相等，则
再次用朴素算法比较，相等则相等。这点思路类似于布隆过滤器。如果hash不相等，则二者必然不匹配。

## KMP算法

当字符串不匹配时，其实已经知道了前面已经匹配成功的那一部分字符。KMP的思路就是利用已知信息，提高
效率。参考阮一峰的讲解

https://www.bilibili.com/video/av11866460?from=search&seid=17425875345653862171


http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html

## BM算法


https://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html