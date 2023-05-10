# Json-Parser

## 说明

用于解析json内部结构，用token的方式进行展示

## 使用方法

### 编译

```sh
make generate
make compile
```

### 运行

```sh
./release/json_parser -f <待解析json文件>
```

## 示例

```text
# ./release/json_parser -f test.json

Type: J_OBJECT
Value:
	Type: J_STRING	Value:"Langshen"
	Type: J_OBJECT_KEY_VALUE_PAIR	Value:"Name": "Langshen"
	Type: J_STRING	Value:"LuLu"
	Type: J_STRING	Value:"26"
	Type: J_ARRAY	Value:[
      123,
      456
    ]
		Type: J_NUMBER	Value:123
		Type: J_NUMBER	Value:456
	Type: J_ARRAY	Value:[
    "LuLu",
    "26",
    [
      123,
      456
    ]
  ]
	Type: J_OBJECT_KEY_VALUE_PAIR	Value:"MyWife": [
    "LuLu",
    "26",
    [
      123,
      456
    ]
  ]
	Type: J_STRING	Value:"Son1"
	Type: J_OBJECT_KEY_VALUE_PAIR	Value:"Name": "Son1"
    
	Type: J_OBJECT	Value:{
      "Name": "Son1"
    }
	Type: J_STRING	Value:"Son2"
	Type: J_OBJECT_KEY_VALUE_PAIR	Value:"Name": "Son2"
    
	Type: J_OBJECT	Value:{
      "Name": "Son2"
    }
	Type: J_STRING	Value:"Son3"
	Type: J_OBJECT_KEY_VALUE_PAIR	Value:"Name": "Son3"
```
