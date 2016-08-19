#ifndef KPQZ_GAME_LOGIC_HEAD_FILE
#define KPQZ_GAME_LOGIC_HEAD_FILE

#pragma once

#include "Define.h"
#include "SpriteDefine.h"

//////////////////////////////////////////////////////////////////////////

//��ֵ����
#define	LOGIC_MASK_COLOR			0xF0								//��ɫ����
#define	LOGIC_MASK_VALUE			0x0F								//��ֵ����

#define	MAX_COUNT					5

//�˿�����
#define OX_VALUE0					0									//�������
#define OX_THREE_SAME				102									//��������
#define OX_FOUR_SAME				103									//��������
#define OX_FOURKING					104									//��������
#define OX_FIVEKING					105									//��������
#define OX_FIVEXNIU					106									//��Сţ����

//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////

//��Ϸ�߼���
class KPQZGameLogic
{
	//��������
private:
	static BYTE						m_cbCardListData[52];				//�˿˶���

	//��������
public:
	//���캯��
	KPQZGameLogic();
	//��������
	virtual ~KPQZGameLogic();

	//���ͺ���
public:
	//��ȡ����
	BYTE GetCardType(BYTE cbCardData[], BYTE cbCardCount);
	//��ȡ��ֵ
	BYTE GetCardValue(BYTE cbCardData) { return cbCardData&LOGIC_MASK_VALUE; }
	//��ȡ��ɫ
	BYTE GetCardColor(BYTE cbCardData) { return cbCardData&LOGIC_MASK_COLOR; }
	//��ȡ����
	BYTE GetTimes(BYTE cbCardData[], BYTE cbCardCount);
	
	BYTE GetTimes(BYTE cardType);
	//---

	BYTE GetTimes_5(BYTE cbCardData[], BYTE cbCardCount);

	//��ȡţţ
	bool GetOxCard(BYTE cbCardData[], BYTE cbCardCount);
	//��ȡ����
	bool IsIntValue(BYTE cbCardData[], BYTE cbCardCount);

	//���ƺ���
public:
	//�����˿�
	void SortCardList(BYTE cbCardData[], BYTE cbCardCount);
	//�����˿�
	void RandCardList(BYTE cbCardBuffer[], BYTE cbBufferCount);

	//���ܺ���
public:
	//�߼���ֵ
	BYTE GetCardLogicValue(BYTE cbCardData);
	//�Ա��˿�
	bool CompareCard(BYTE cbFirstData[], BYTE cbNextData[], BYTE cbCardCount,int FirstOX,int NextOX);
};

//////////////////////////////////////////////////////////////////////////

#endif