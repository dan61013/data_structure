# Data Structure

參考資料: [擁抱「資料結構」的「演算法」](https://ithelp.ithome.com.tw/users/20129841/ironman/3300)
,[【Python】Single Linked List(單向鏈結串列) 資料結構實作 | 愛喝咖啡 Ｘ 咖啡程式](https://lovedrinkcafe.com/python-single-linked-list/)
## 何謂資料結構

資料結構: 是以何種方式**儲存**在電腦裡，並以何種方式進行**分類**與**排序**。
1. 存放位置
2. 儲存方式
3. 分類
4. 排序

## Ch01

### Array 陣列 (線性串列)

特性與限制:
1. 用來**儲存**一群**相同類型**的資料
2. 會使用一段**連續**的記憶體空間來存放
3. 必須**明確定義**要存放多少**數量**的資料
4. 可透過**索引**快速存取資料
5. 不方便追加或刪除資料

Example -> 藥盒裝一周的保健藥品:
1. 盒子用來裝保健藥品 -> 不能裝感冒藥或其他藥品
2. 有一排的連續格子拿來裝保健藥品
3. 總共有7格(周一~周日)
4. 盒子上的標記(索引)，代表可以直接取走當天需要的藥品
5. 吃了一段時間後，想要變更順序，需要整體的大調整

```python
box = [
    "維他命D", "葉黃素", "蔓越莓錠", "B群", "綜合維他命", "益生菌", "維他命C"
]
# box[0] = "維他命D"
# box[2] = "蔓越莓錠"
```

### 維度

- 一維: 一條線
- 二維: 一個平面
- 三維: 一個立方體
- N維: 例如三維加上時間，等其他條件

### 多維陣列 (Multidimensional Arrays)

#### One Dimensional Array

一維陣列，可以存放多個元素，類似串列
```python
import numpy
# One Dimensional Array
arr = numpy.array([1, 2, 3, 4, 5, 6, 7])
print(arr[2]) # 星期三
```

#### Two Dimensional Array

二維陣列，除了星期幾以外，再新增**時段**
```python
import numpy
# Two Dimensional Array
arr = numpy.array([
    [1, 2, 3, 4, 5, 6, 7], # 早
    [1, 2, 3, 4, 5, 6, 7], # 中
    [1, 2, 3, 4, 5, 6, 7] # 晚
])
print(arr[1, 4]) # 週五的中午
```

#### Three Dimensional Array
三維陣列，一個月(四周)；一個星期(七天)；每天(三個時段)

```python
import numpy
# Three Dimensional Array
arr = numpy.array([
    # 第一周
    [[1, 2, 3, 4, 5, 6, 7],
    [1, 2, 3, 4, 5, 6, 7],
    [1, 2, 3, 4, 5, 6, 7]],
    # 第二周
    [[1, 2, 3, 4, 5, 6, 7],
    [1, 2, 3, 4, 5, 6, 7],
    [1, 2, 3, 4, 5, 6, 7]],
    # 第三周
    [[1, 2, 3, 4, 5, 6, 7],
    [1, 2, 3, 4, 5, 6, 7],
    [1, 2, 3, 4, 5, 6, 7]],
    # 第四周
    [[1, 2, 3, 4, 5, 6, 7],
    [1, 2, 3, 4, 5, 6, 7],
    [1, 2, 3, 4, 5, 6, 7]]
])
print(arr[3, 1, 5]) # 第四周的星期四中午
```

## Ch02

### Linked List 連接串列

Linked List，有分成**單向**、**雙向**、**環狀**

是一個有相似資料型態序列的nodes(節點)，
每一個node儲存一個data物件，與指向下一個node位址的pointer

特色:
- 節點資料的type、記憶體大小不用相同
- 不支援如stack的隨機存取(Random Access)
- 只能做循序純取(Sequential Access)
- 需要額外:
    1. head: 指向第一個node
    2. tail: 指向最後一個node
    3. 在依循搜尋時，current會指向當前的node

it邦介紹:
1. 每個元素都是獨立的，與Array不同，不是一體成形
2. 可以單獨使用，也可以合併使用
3. 易於新增刪除、調整順序

※ 人脈弱連結:

A的朋友B，B的朋友C的表哥是明星D，所以A想要與明星D聯繫上，就必須:
```
A -> B -> C -> 明星D
```

### Singly Linked List

單向連結串列

特性:
1. 不需要預留固定數量且一段連續的儲存空間
2. 一個節點包含**資料**與**指標**
3. 無索引，必須**單向**依序讀取**節點**，透過**指標**，才知道下一個要讀取哪個節點(無法像陣列透過索引就能讀取資料)
4. 插入或新增節點很方便，只要改變指標即可
5. 結尾是None(python) -> Null

### Double Linked List

雙向連結串列

- 每個node都會有previous node and next node
- 新增時要改變4個pointer
- 刪除時要改變2個pointer (previous node.next and next node.previous)
- 結尾是 None(python) -> Null

### Circular Linked List

環狀連結串列

- 將單向連結串列**最後一個節點**的指標，指向第一個節點

## Stack

### 堆疊

- 抽象資料型態 (Abstract Data Type, ADT): 大範圍，不具體、不仔細的資料
- 堆疊是一種抽象資料型態

特性:

1. 只能從最頂端存取資料
2. 只能從最頂端新增或刪除資料
3. 資料的存取必須符合後進先出 (Last In First Out, LIFO)

### 堆疊的ADP

只要某一個類有提供以下方法，我們都可以稱此類為一種堆疊

1. Create: 可以建立一個空堆疊
2. Push: 可以在頂端新增資料，並得到一個新堆疊
3. Pop: 可以刪除頂端資料，並得到一個新堆疊
4. Peek: 回傳堆疊頂端的資料