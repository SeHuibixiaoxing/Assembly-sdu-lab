;�������ʽ ������
;��Ȩ����(C): AoGo 2005+
;http://www.aogosoft.com
;����ҵ������ֱ���ڴ�����ʹ��,��ҵ����������Aogosoftͬ��,Aogosoft����׷��Ȩ��
;��ϸʹ�÷�����ο� MASMPlus �����ĵ���"�������ʽ"һ��
;=====================================================================================
EF_DEC						=   1h		;���ϲ���,Ĭ������
EF_USEEXPRESS				=   2h		;ʹ�ñ���ʽ
EF_WORDCASE					=   4h		;���ִ�Сд
EF_MATCHWORD				=   8h		;ƥ����������,����EF_USEEXPRESSʱ�˱�־��Ч
EF_BEGINNOTLINEBEGIN		=  10h		;��ʼ��ַ��������
EF_ENDNOTLINEEND			=  20h		;������ַ������β
EF_ENDISSIZE				=  40h		;������ַ��һ������(��EF_DEC��Ч)
EF_FINDONCE					=  80h		;ֻ����һ��,ֻ��EF_USEEXPRESS��Ч���Ҷ�EF_DEC��Ч)
EF_MODIFLINESTARTEND		= 100h		;������������β
EF_DOUBLEISWORD			= 200h		;�����ַ�Ҳ�ǵ���
EF_RANGENOTCASE			= 400h		;����[]�ڵ��ַ����ǲ���Сд
EF_RESERVED					= 800h		;��������,�벻Ҫ����,�����ڶ��β���,���ڲ��Զ�ȷ��
									;�ַ���,��ʼ��ַ,������ַ,Ҫ���ҵ��ַ�����ַ,���ز�����Ϣ�����ַ,�����С,���ұ�־EF_*
ExpressSearch				PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
;-------------------------------------------
;����ʽ����ʱ�п��ܷ����Ĵ���:
EFERR_NOTCONST				equ -1		;û�г�������
EFERR_EXPNOTSUPPORT		equ -2		;��������ʹ�÷���
EFERR_NOTCLOSEBRACKET	equ -3		;û�йر�����
EFERR_EMPTYEXPRESS		equ -4 		;�յı���ʽ,()/[]/{}/<>
EFERR_NOTEXISTEXP			equ -5		;����ı���ʽ������,��ʹ��\],\),\>�ȵ�
EFERR_NOTBYONSELF			equ -6		;����ʽ���Ų��ܵ���ʹ��
EFERR_NOTLOOPEND			equ -7		;����?*/?+�������ý�������,ͬʱ,*/+����?��˵��һ����
EFERR_DEADLOOP				equ -8		;��ʹ��*/+�ı���ʽ�������������ʽ���ǿɺ��Ե�,��(.*)+,��Ϊ.*���ǳɹ�,����
												;��+Ҫ��ɹ�ʱ����,����һ����ѭ��.
EFERR_INVALIDEXP			equ -9		;��Ч����ʽ,��%*,��Ϊ*�ǿɺ��Է���,����������ʽ���ǳɹ�.
;--------------------------------------------
;�ڲ��ַ��������ΪPublic,�ڴ�����ʹ��Extrn DefCharTable :DWORD������
CF_WORD			equ        1h		;����
CF_NUMBER		equ        2h		;����
CF_HEX			equ        4h		;ʮ������
CF_BIN			equ        8h		;������
CF_UPCHAR		equ       10h		;��д�ַ�
CF_LOWCHAR		equ       20h		;Сд�ַ�
CF_COMMENT		equ       40h		;ע���ַ�
CF_COMMENTEND	equ       80h		;ע�͵ڶ����ַ�
CF_TAB			equ      100h		;�﷨�߶����
CF_SPACE			equ      200h		;�ո�
CF_ENTER			equ      400h		;�س�
CF_WARP			equ      800h		;���з�
CF_MATCH			equ     1000h		;������,��˫����
CF_SELFMATCH	equ     2000h		;������,�絥����
CF_INVALID		equ 40000000h		;��Ч/�������ַ��ַ�
CF_DOUBLEBYTE	equ 80000000h		;�����ַ���