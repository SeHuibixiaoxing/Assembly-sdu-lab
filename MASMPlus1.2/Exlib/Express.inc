;正则表达式 函数库
;版权所有(C): AoGo 2005+
;http://www.aogosoft.com
;非商业软件可直接在代码中使用,商业软件请征得Aogosoft同意,Aogosoft保留追究权力
;详细使用方法请参考 MASMPlus 帮助文档中"正则表达式"一节
;=====================================================================================
EF_DEC						=   1h		;向上查找,默认向下
EF_USEEXPRESS				=   2h		;使用表达式
EF_WORDCASE					=   4h		;区分大小写
EF_MATCHWORD				=   8h		;匹配整个单词,包含EF_USEEXPRESS时此标志无效
EF_BEGINNOTLINEBEGIN		=  10h		;开始地址不是行首
EF_ENDNOTLINEEND			=  20h		;结束地址不是行尾
EF_ENDISSIZE				=  40h		;结束地址是一个长度(对EF_DEC无效)
EF_FINDONCE					=  80h		;只查找一遍,只对EF_USEEXPRESS有效并且对EF_DEC无效)
EF_MODIFLINESTARTEND		= 100h		;修正行首与行尾
EF_DOUBLEISWORD			= 200h		;中文字符也是单词
EF_RANGENOTCASE			= 400h		;符号[]内的字符总是不大小写
EF_RESERVED					= 800h		;保留符号,请不要设置,它用于二次查找,由内部自动确认
									;字符表,开始地址,结束地址,要查找的字符串地址,返回查找信息数组地址,数组大小,查找标志EF_*
ExpressSearch				PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
;-------------------------------------------
;表达式查找时有可能发生的错误:
EFERR_NOTCONST				equ -1		;没有常数定义
EFERR_EXPNOTSUPPORT		equ -2		;不能这样使用符号
EFERR_NOTCLOSEBRACKET	equ -3		;没有关闭括号
EFERR_EMPTYEXPRESS		equ -4 		;空的表达式,()/[]/{}/<>
EFERR_NOTEXISTEXP			equ -5		;多余的表达式结束符,请使用\],\),\>等等
EFERR_NOTBYONSELF			equ -6		;表达式符号不能单独使用
EFERR_NOTLOOPEND			equ -7		;对于?*/?+必须设置结束条件,同时,*/+对于?来说是一样的
EFERR_DEADLOOP				equ -8		;在使用*/+的表达式里面的整个表达式均是可忽略的,如(.*)+,因为.*总是成功,后面
												;的+要求成功时继续,这是一个死循环.
EFERR_INVALIDEXP			equ -9		;无效表达式,如%*,因为*是可忽略符号,则上述表达式总是成功.
;--------------------------------------------
;内部字符表已输出为Public,在代码中使用Extrn DefCharTable :DWORD来引用
CF_WORD			equ        1h		;单词
CF_NUMBER		equ        2h		;数字
CF_HEX			equ        4h		;十六进制
CF_BIN			equ        8h		;二进制
CF_UPCHAR		equ       10h		;大写字符
CF_LOWCHAR		equ       20h		;小写字符
CF_COMMENT		equ       40h		;注释字符
CF_COMMENTEND	equ       80h		;注释第二个字符
CF_TAB			equ      100h		;语法线对齐符
CF_SPACE			equ      200h		;空格
CF_ENTER			equ      400h		;回车
CF_WARP			equ      800h		;换行符
CF_MATCH			equ     1000h		;包含符,如双引号
CF_SELFMATCH	equ     2000h		;包含符,如单引号
CF_INVALID		equ 40000000h		;无效/无意义字符字符
CF_DOUBLEBYTE	equ 80000000h		;中文字符首