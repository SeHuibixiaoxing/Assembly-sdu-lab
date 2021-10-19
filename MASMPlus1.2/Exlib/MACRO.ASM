
; ------------------- UNICODE support macros for MASM32 -------------------

comment * -----------------------------------------------
      macro to declare UNICODE string data in the .DATA
      section.
      SYNTAX:
      WSTR MyString,"This is a test"
      string length limit = 118 charachers
      control characters like < > etc .. cannot be used
      in the string.
      ------------------------------------------------- *
    WSTR MACRO iname,text:VARARG
        ustrng1 equ <>
        ustrng2 equ <>
        ustrng3 equ <>

        addstr1 equ <>
        addstr2 equ <>
        addstr3 equ <>
        cnt = 0

        slen SIZESTR <text>

      ;; ------------------------------------------------
      ;; test for errors in length or missing quotations
      ;; ------------------------------------------------
        if slen gt 118
          echo -----------------------
          echo *** STRING TOO LONG ***
          echo -----------------------
        .ERR
        EXITM
        endif

        qot1 SUBSTR <text>,1,1
        IFDIF qot1,<">
          echo -----------------------------
          echo *** MISSING LEADING QUOTE ***
          echo -----------------------------
        .ERR
        EXITM
        ENDIF

        qot2 SUBSTR <text>,slen,1
        IFDIF qot2,<">
          echo ------------------------------
          echo *** MISSING TRAILING QUOTE ***
          echo ------------------------------
        .ERR
        EXITM
        ENDIF

      ;; ------------------------------------------------
      ;; loop through the characters in the string adding
      ;; them in a WORD formatted form to the end of each
      ;; string depending on the length.
      ;; ------------------------------------------------
        nustr SUBSTR <text>,2,slen-2
      % FORC arg, <nustr>
          if cnt lt 1
            addstr1 CATSTR addstr1,<">,<arg>,<">
          elseif cnt lt 40
            addstr1 CATSTR addstr1,<,">,<arg>,<">
            
          elseif cnt lt 41
            addstr2 CATSTR addstr2,<">,<arg>,<">
          elseif cnt lt 80
            addstr2 CATSTR addstr2,<,">,<arg>,<">

          elseif cnt lt 81
            addstr3 CATSTR addstr3,<">,<arg>,<">
          elseif cnt lt 120
            addstr3 CATSTR addstr3,<,">,<arg>,<">
          endif
          cnt = cnt + 1
        ENDM

      ;; ------------------------------------------------
      ;; The following three blocks append the 00 to the
      ;; end of the string depending on how long it is
      ;; ------------------------------------------------
        if cnt lt 41
        addstr1 CATSTR addstr1,<,00>
        endif
          ustrng1 CATSTR ustrng1,<iname>,< dw >,addstr1
          ustrng1
        if cnt lt 41
          EXITM
        endif

        if cnt lt 81
          addstr2 CATSTR addstr2,<,00>
        endif
          ustrng2 CATSTR ustrng2,< dw >,addstr2
          ustrng2
        if cnt lt 81
          EXITM
        endif

        addstr3 CATSTR addstr3,<,00>
        ustrng3 CATSTR ustrng3,< dw >,addstr3
        ustrng3
    ENDM
    ;; -------------------------------------------------

  ; ******************************
  ; FUNCTION version of the above.
  ; ******************************
    uni$ MACRO text:VARARG

        LOCAL addstr1
        LOCAL iname

        ustrng1 equ <>
        ustrng2 equ <>
        ustrng3 equ <>

        addstr1 equ <>
        addstr2 equ <>
        addstr3 equ <>
        cnt = 0

        slen SIZESTR <text>

     ;; ------------------------------------------------
     ;; test for errors in length or missing quotations
     ;; ------------------------------------------------
        if slen gt 118
          echo -----------------------
          echo *** STRING TOO LONG ***
          echo -----------------------
        .ERR
        EXITM <>
        endif

        qot1 SUBSTR <text>,1,1
        IFDIF qot1,<">
          echo -----------------------------
          echo *** MISSING LEADING QUOTE ***
          echo -----------------------------
        .ERR
        EXITM <>
        ENDIF

        qot2 SUBSTR <text>,slen,1
        IFDIF qot2,<">
          echo ------------------------------
          echo *** MISSING TRAILING QUOTE ***
          echo ------------------------------
        .ERR
        EXITM <>
        ENDIF

      ;; ------------------------------------------------
      ;; loop through the characters in the string adding
      ;; them in a WORD formatted form to the end of each
      ;; string depending on the length.
      ;; ------------------------------------------------
        nustr SUBSTR <text>,2,slen-2
      % FORC arg, <nustr>
          if cnt lt 1
            addstr1 CATSTR addstr1,<">,<arg>,<">
          elseif cnt lt 40
            addstr1 CATSTR addstr1,<,">,<arg>,<">
            
          elseif cnt lt 41
            addstr2 CATSTR addstr2,<">,<arg>,<">
          elseif cnt lt 80
            addstr2 CATSTR addstr2,<,">,<arg>,<">

          elseif cnt lt 81
            addstr3 CATSTR addstr3,<">,<arg>,<">
          elseif cnt lt 120
            addstr3 CATSTR addstr3,<,">,<arg>,<">
          endif
          cnt = cnt + 1
        ENDM

        .data
      ;; ------------------------------------------------
      ;; The following three blocks append the 00 to the
      ;; end of the string depending on how long it is
      ;; ------------------------------------------------
        if cnt lt 41
        addstr1 CATSTR addstr1,<,00>
        endif
          ustrng1 CATSTR ustrng1,<iname>,< dw >,addstr1
          ustrng1
        if cnt lt 41
          .code
          goto mclbl
        endif

        if cnt lt 81
          addstr2 CATSTR addstr2,<,00>
        endif
          ustrng2 CATSTR ustrng2,< dw >,addstr2
          ustrng2
        if cnt lt 81
          .code
          goto mclbl
        endif

        addstr3 CATSTR addstr3,<,00>
        ustrng3 CATSTR ustrng3,< dw >,addstr3
        ustrng3
          .code

        :mclbl

        EXITM <OFFSET iname>

    ENDM
    ;; -------------------------------------------------

      literal MACRO quoted_text:VARARG
        LOCAL local_text
        .data
          local_text db quoted_text,0
        .code
        EXITM <local_text>
      ENDM

      CTXT MACRO quoted_text:VARARG
        EXITM <offset literal(quoted_text)>
      ENDM

    $casflg equ <>
    $casvar equ <>
    $casstk equ <>
    
    switch macro _var:req, _reg:=<eax>
        mov _reg, _var
        $casstk catstr <_reg>, <#>, $casflg, <#>, $casstk
        $casvar equ _reg
        $casflg equ <0>         ;; 0 = emit an .if, 1 an .elseif
    endm
    
    case macro _args:vararg     ;; like Pascal: case id1. id4 .. id8, lparam, ...
                                ;; does an or (case1 || case2 || case3...)
      $cas textequ <>
      irp $v, <_args>         ;; for each case
          t@ instr <$v>, <..> ;; range ?
          if t@               ;; yes
              $LB substr <$v>, 1, t@-1                  ;; lbound = left portion
              $LB catstr <(>, $casvar, <!>=>, $LB, <)>  ;; ($casvar >= lbound)
              $UB substr <$v>, t@+2                     ;; ubound = right portion
              $UB catstr <(>, $casvar, <!<=>, $UB, <)>  ;; ($casvar <= ubound)
              $t catstr <(>, $LB, <&&> , $UB,<)>        ;; (($casvar >= $lb) && ($casvar <= $ub))
          else    ;; no, it's a value (var/const)
              $t catstr <(>, $casvar, <==>, <$v>, <)>   ;; ($casvar == value)
          endif
          $cas catstr <|| >, $t, $cas                   ;; or this case w/ others
      endm
      $cas substr $cas, 3 ;; lose the extra "|| " in front
        ifidn $casflg, <0> ;; 0 = 1'st case
            % .if $cas ;; emit ".if"
        else ;; all others
            % .elseif $cas ;; emit ".elseif"
        endif
        $casflg equ <1> ;; NOT 1'st
    endm
    
    default macro _default:vararg
        .else
        _default
    endm
    
    endsw macro _cmd:vararg
        ifidn $casstk, <>
            .err <Endsw w/o Switch>
        else
            t@ instr $casstk, <#>
            $casvar substr $casstk, 1, t@-1
            $casstk substr $casstk, t@+1
            t@ instr $casstk, <#>
            $casflg substr $casstk, 1, t@-1
            ifidn $casstk, <#>
                $casstk equ <>
            else
                $casstk substr $casstk, t@+1
            endif
            .endif
        endif
    endm

MAKEDWORD MACRO LoWord,HiWord
  mov ax, HiWord
  ror eax, 16
  mov ax, LoWord
ENDM
LOWORD MACRO SrcDWORD
  mov  eax,SrcDWORD
  and  eax,0FFFFh
ENDM
LOWORD MACRO SrcDWORD
  mov  eax,SrcDWORD
  shr  eax,16
ENDM
SplitDWORD macro SrcDWORD
  mov  eax,SrcDWORD
  mov  ecx,eax
  and  eax,0FFFFh
  mov  eax,SrcDWORD
  shr  eax,16
ENDM

;以下的宏是MASMPlus一系列的宏
;====================================================================================
;自由调用宏 by AoGo
;-------------------------------------
;与invoke的区别是fcall不检查参数个数和类型是否和声明一致(自由嘛),常用在调用DLL函数上
;同时它会自动处理字符串并进行声明
;会自动检查在使用eax之前是否使用addr引用局部变量,如:
;@fcall MessageBox,hWnd,eax,addr buffer,0
;会提示错误:addr overwrite eax
;@fcall eax,hWnd,eax,addr buffer,0
;会提示错误:addr overwrite Function [eax]
;但这样无错 fcall MessageBox,hWnd,addr buffer,eax,0
;@fcall MessageBox,0,"自由调用","成功",0
;@fcall MessageBox,0,addr buffer,CTXT("Hello"),0
_VAR_NUMERIC_ = 0
@fcall MACRO FunArgs:VARARG
	LOCAL txt, arg,curr,buseeax,lpquot,local_text
	txt TEXTEQU <>
	buseeax = 0
	;反转参数
	%FOR arg, <FunArgs>
	  txt CATSTR <arg>, <!,>, txt
	ENDM
	txt SUBSTR  txt, 1, @SizeStr( %txt ) - 1
	;压入所有参数
	:PushNext
		curr INSTR 1,txt,<!,>
		IF curr NE 0
			lpquot SUBSTR txt,1,1
			arg  SUBSTR txt,1,curr-1
			txt  SUBSTR txt,curr+1,@SizeStr(% txt)-curr
			IF @SizeStr(% txt) GE 1
				curr INSTR 1,arg,<!addr>
				IF curr NE 0
					arg SUBSTR arg,6,@SizeStr(% arg)-5
					buseeax=1
					lea eax,arg								;使用了eax,做一个标记,如果在这之后直接使用push eax时,显示错误
					push eax
				ELSE
					ifidn lpquot,<!">
						local_text CATSTR <!??__HA__??>,%_VAR_NUMERIC_
						_VAR_NUMERIC_ = _VAR_NUMERIC_+1
						.data
							local_text db arg,0
						.code
						push offset local_text
					elseIF buseeax EQ 1
						ifidn arg,<!eax>
							.err <addr overwrite eax>	;显示错误在使用eax之前使用了addr,中止编译
						endif
						push arg
					else
						push arg
					ENDIF
				ENDIF
				goto PushNext
			ENDIF
		ENDIF
		IF buseeax EQ 1									;如果已经修改了eax,检查函数调用是否使用了eax
			ifidn txt,<!eax>
				.err <addr overwrite Function [eax]>	;显示错误在使用eax之前使用了addr,中止编译
			endif
		ENDIF
		call txt
ENDM
;函数嵌套调用宏 by AoGo.
;==================================
;可以像c一样方便地调用函数,能自动处理字符串并定义,同时可在嵌套的同时创建并返回全局变量
;mov i,@(MessageBox,0,"做为指令参数使用","Welcome",0)
;在函数名前使用#号,可以自动创建并将函数返回值放入变量中.使用&号,表示当前这个API返回的是&后的符号地址
;&buffer展开后为lea eax,buffer,如果#与&同时存在,宏会在lea eax,*之前mov #*,eax,也就是函数的返回值总是
;保存在创建的变量中,另外,#*不能与已有的变量重名,只能创建新的,如果已经存在一个变量,请直接使用,不要加#号
;invoke MessageBox,0,@(#iStrSize=wsprintf,&buffer,CTXT("%d"),eax),0,0
;上述语句执行后,iStrSize中的值是wsprintf的返回值也就是填充后的缓冲大小,&buffer表示将addr buffer交给MessageBox
;invoke ExitProcess,@(#a=MessageBox,0,@(#hModule=GetModuleFileName,0,&buffer,sizeof buffer),"嵌套使用",0)
;需要的话,可以单独使用,在API名字前加上*号即可:
;@(*MessageBox,0,"单独使用","Welcome",0)
;宏支持至少20层嵌套.不过建议嵌套保持在5层以下.以免代码混乱.
@ Macro args:VARARG
	local lpargs,lpends,RetSize,lpAddressPos,retvar,varstr,startpos
	LOCAL arg,lpquot,local_text,InvokeAPI,paramindex,notretvalue
	InvokeAPI	TEXTEQU <invoke >
	paramindex	=0
	retvar		=0
	startpos		=0
	varstr		SUBSTR <args>,1,1
	ifidn varstr,<!*>
		notretvalue=0
		lpargs	SUBSTR <args>,2,@SizeStr(<args>)-1
		startpos=1
	else
		notretvalue=1
		startpos=0
		lpargs	TEXTEQU <args>
	endif
	lpAddressPos INSTR 1,<args>,<!,>	;找到xx=xx(,)
		retvar INSTR 1,<args>,<!=>		;找到xx(=)xx,
		if retvar ne 0
			if (retvar lt lpAddressPos) or (lpAddressPos eq 0)
				varstr SUBSTR <args>,startpos+1,1
				ifidn varstr,<!#>			;如果找到的变量前有一个#,定义它.
					varstr SUBSTR <args>,startpos+2,retvar-startpos-2
					.data?
						varstr dd ?
					.code
				else
					varstr SUBSTR <args>,startpos+1,retvar-startpos-1
				endif
				lpargs SUBSTR <args>,retvar+1,@SizeStr(<args>)-retvar
			else
				retvar =0
			endif
		endif
	startpos=startpos+retvar
	lpAddressPos INSTR 1,<args>,<!&>
	if lpAddressPos ne 0					;如果找到&符,表示需要返回这个地址
		lpargs SUBSTR <args>,startpos+1,lpAddressPos-startpos-1
		lpargs CATSTR lpargs,<addr >	;加上addr
		lpends SUBSTR <args>,lpAddressPos+1,@SizeStr(<args>)-lpAddressPos
		lpargs CATSTR lpargs,lpends
		RetSize INSTR 1,lpends,<!,>	;取这个参数
		if RetSize ne 0
			lpends SUBSTR <args>,lpAddressPos+1,RetSize-1
		else
			lpends SUBSTR <args>,lpAddressPos+1,@SizeStr(<args>)-lpAddressPos
		endif
	endif
	;-----------------------------------------------------
	;创建invoke行.
	%FOR arg, <lpargs>
		if paramindex ne 0
			InvokeAPI CATSTR InvokeAPI,<!,>
		endif
		lpquot SUBSTR <arg>,1,1
		ifidn lpquot,<!">
			local_text CATSTR <!_??xx??>,%_VAR_NUMERIC_
			_VAR_NUMERIC_ = _VAR_NUMERIC_+1
			.data
				local_text db arg,0
			.code
			InvokeAPI CATSTR InvokeAPI,<offset local_text>
		else
			InvokeAPI CATSTR InvokeAPI,<arg>
		ENDIF
		paramindex=paramindex+1
	ENDM
	InvokeAPI
	;-----------------------------------------------------
	if retvar ne 0
		mov varstr,eax
	endif
	if lpAddressPos ne 0
		lea eax,lpends						;入栈
	endif
	if notretvalue ne 0
		EXITM <eax>
	endif
ENDM

;创建一个数组,并返回它的全部索引,并自动创建数组常数.
;例子:ARRAY szNAME,8,"李明|成吉思汗|中国|你好"
;然后用以下名字访问字符串指针(IndexOfszName是自动生成的常数,值为当前字符串中各个数组的的偏移
;	szNAME[IndexOfszNAME*0]
;  szNAME[IndexOfszNAME*1]
;  szNAME[IndexOfszNAME*2]
;  szNAME[IndexOfszNAME*3]
ARRAY macro _name,_size,_string:VARARG
local i1,i2,quot,_str,_arr,var
   quot SUBSTR <_string>,1,1;开头的是单引号还是双引号
   _str SUBSTR <_string>,2,@SizeStr(<_string>)-2;去掉引号
   .data
      _var db 0
   i1=1
:next
   if i1 LE @SizeStr(%_str)
      i2 INSTR i1,_str,<|>
      if i2
         _arr SUBSTR _str,i1,i2-i1
         len SIZESTR _arr
         _arr CATSTR quot,_arr,quot
         db _arr,(_size-len+1) dup(0)
         i1=i2+1
         goto next
      else;最后一个词
         _arr SUBSTR _str,i1
         len SIZESTR _arr
         _arr CATSTR quot,_arr,quot
         db _arr,(_size-len+1) dup(0)
         db 0         
      endif
   endif
   .code
   _name equ DWORD ptr offset _var+1
   Indexof&_name equ (_size+1);创建一个Index常量
   IndexOf&_name equ (_size+1);
   endm
;高级字符串定义宏,支持转义符,能处理\\ \n \t \0
;例子invoke MessageBox,hWnd,CTEXT("欢迎使用MASMPlus\n\n\t字符串定义由CTEXT宏\n\n作者:鬼龙之舞"),0,0
;感谢[鬼龙之舞]费心编写.有意见请联系鬼兄
;Mail:	k_badboy@sohu.com 
;主页:	http://kbadboy.yeah.net
CTEXT macro text:VARARG
   local result,var
	local quot,text_noquot,i,j
	local find,replace
	local _char,comma
	
	inplacing=0	;控制是在转换还是正常添加

   quot SUBSTR <text> ,1,1 ;第一个字符是单引号还是双引号

	text_noquot SUBSTR <text>,2,@SizeStr(<text>)-2;a为去掉左右的引号后的内容
	ife @InStr(1,<text>,<\>)
		.data
			var db text,0
		.code
			exitm<offset var>
	endif
	result textequ <>
	comma textequ <!,>
	i=1
:nextchar
	_char SUBSTR text_noquot,i,1
	ifidn _char,<\>
		find SUBSTR text_noquot,i+1,1
		ifidn find,<n>;\n转换为13,10
			replace textequ <13!,10>
			i=i+1
		elseifidn find,<t>;\t转换为9
			replace textequ <09>
			i=i+1
		elseifidn find,<0>;\0
			replace textequ <00>
			i=i+1
		elseifidn find,<\>;\\为不转换
			replace textequ quot
			if @SizeStr(%text_noquot)-2 ;\\在最后,直接添加\
				replace CATSTR replace,<\>,quot
				i=i+1
			else;\\不是在最后，添加\和它后面的那个字符
				find SUBSTR text_noquot,i+2,1
				replace CATSTR replace,<\>,find,quot
				i=i+2
			endif
		else
			replace textequ quot,_char,quot
		endif
		if inplacing
			result CATSTR result,comma
		endif
		result CATSTR result,replace
		inplacing=1
	else
		if inplacing
			result CATSTR result,comma
			inplacing=0
		endif
		result CATSTR result,quot,_char,quot,comma
	endif
	if i NE @SizeStr(%text_noquot)
		i=i+1
		goto nextchar
	endif
	comma SUBSTR result,@SizeStr(%result),1
	ifidn comma,<!,>
		result SUBSTR result,1,@SizeStr(%result)-1
	endif
	
   .data
			var db 0
			j=1
			:nextp
			if j+2 LT @SizeStr(%result)
				i INSTR j+2,result,<!,>
				if i
					find SUBSTR result,j,i-j					
					db find					
					j=i+1
					goto nextp
				endif
			endif
			find SUBSTR result,j
			db find
			db 0		
	.code
   exitm<offset var+1>
endm

;智能宏的所谓智能就是:如果我们定义一个变量的首字母是g(global),就把它定义为全局标签
;在MASM中,以一个冒号结束的标签是局部标签(如果这个标签位于过程内)
;以2个冒号结束的标签是全局标签
;这个宏除了方便外,还有2个好处
;(1)反反汇编
;在ctext宏中,字符串是被添加到data节中,而在szText中,字符串直接定义在当前位置
;在一定的程度上,给反汇编带来一定的影响(w32asm也无法正常反汇编)
;(2)使用更方便
;由于我们使用的是标签,所以要访问字符串除了用常规的offset,addr外,
;还可以直接用变量名
;例子:szText gtext,"全局变量"		任何地方都可以引用
;例子:szText sztext,"局部变量"   只能在当前过程中引用
szText macro name,text:VARARG 
	local l
	jmp l
	ifidn @SubStr(name,1,1),<g>
		name::		;两个冒号是全局标签
		db text,0
	else
		name:
		db text,0
	endif
	l:
	endm