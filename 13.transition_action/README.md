# 13.transition_action

## 说明

transition_action项目用于演示四种transition actions的示例

### Transition actions

* `expr > action` Entering Action
* `expr @ action` Finishing Action
* `expr $ action` All Transition Action
* `expr % action` Leaving Actions

### 说明

* `Entering Action` 进入状态机时执行一次，(不受编写顺序影响)
* `Leaving Actions` 状态机执行完成时执行一次，(不受编写顺序影响)
* `All Transition Action` 状态机中扫描一个字符执行一次，(受编写顺序影响)
* `Finishing Action` 状态机中扫描一个字符执行一次，(受编写顺序影响)

## 使用方法

### 编译

```bash
make
```

### 运行

```bash
./a.out [待验证字符串]
```

### 示例

**digit{1,4} $all_action @end_action >start_action %leave_action**

```bash
# ./a.out "1233 "
Input string: [1233 ]
----start----

Entering Action
All Transition Action
Finishing Action
All Transition Action
Finishing Action
All Transition Action
Finishing Action
All Transition Action
Finishing Action
Leaving Actions: [1233]

----end----

```

**digit{1,4} @end_action $all_action >start_action %leave_action**

```bash
# ./a.out "1233 "
Input string: [1233 ]
----start----

Entering Action
Finishing Action
All Transition Action
Finishing Action
All Transition Action
Finishing Action
All Transition Action
Finishing Action
All Transition Action
Leaving Actions: [1233]

----end----
```

**digit{2,4} @end_action $all_action >start_action %leave_action**

```bash
# ./a.out "1233 "
Input string: [1233 ]
----start----

Entering Action
All Transition Action
Finishing Action
All Transition Action
Finishing Action
All Transition Action
Finishing Action
All Transition Action
Leaving Actions: [1233]

----end----
```

**digit{2,4} $all_action @end_action >start_action %leave_action**

```bash
# ./a.out "1233 "
Input string: [1233 ]
----start----

Entering Action
All Transition Action
All Transition Action
Finishing Action
All Transition Action
Finishing Action
All Transition Action
Finishing Action
Leaving Actions: [1233]

----end----
```
