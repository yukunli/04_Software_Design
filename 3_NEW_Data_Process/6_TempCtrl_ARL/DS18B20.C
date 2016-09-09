
#include "DS18B20.h"
/********************************
 * CODE
 */
 
inline void TEM_18B20_IOinit(void)
{
	EALLOW;
	GpioCtrlRegs.GPBMUX2.bit.TEM_IO=0;
	GpioCtrlRegs.GPBDIR.bit.TEM_IO=0;
	EDIS;
}
//******************��λDS18B20����*****************************
//����������dsPIC30F6014A������������480us��Ȼ���ͷ����߻ص��ߵ�ƽ
//18B20��⵽�����غ��ȵȴ�15-60us��Ȼ������������Ϊ��λ��Ӧ���ź�
//���������ͷ����ߺ󵽸�λ����ʱ��ӦΪ480US
char reset(void)
{
    char presence;
    DQ_LOW();                                //���������͵�ƽ                            
    DELAY_US(480);        					//����5������ʱ480us
    DQ_HIGH();                                //�ͷ����ߵȵ�����������,������15~60us
    DELAY_US(44);                                 
    if(DQ ==0 ) 
    {
    	presence = 1;           //���յ�Ӧ���ź� 
    }         
    else 
    {
    	presence = 0;             //û�н��յ�Ӧ���źţ�������λ
    }
    DELAY_US(210);                                 
    DQ_HIGH(); 
	return presence;
  }
//****************д18b20д�ֽں���*****************************
//��������д����1���Ȱ��������ͣ�Ȼ����15us���ͷ�����
//��������д����0����������������60us
//дһλ����������Ҫ60us
//��λ����֮��������ʱ1us
void write_byte(unsigned char val)
{
 unsigned char  i = 0;
 unsigned char  temp = 0;
 DQ_HIGH(); 
 DELAY_US(2); 
 for(i=8;i>0;i--)
 {
   temp = val & 0x01;                            //���λ�Ƴ�
   DQ_LOW(); 
   DELAY_US(8);                                 //��������5us
   if(temp == 1)
   {
		DQ_HIGH();                   //���д1,���ߵ�ƽ
   }
   DELAY_US(60);                                //��ʱ60us
   DQ_HIGH(); 
   DELAY_US(3);                    //����λ֮�����3us��ʱ
   val = val>>1;                               //����һλ
  }
}
//****************18b20���ֽں���********************************
//����������������������1US��Ȼ���ͷ�
//��������������1��18B20��������״̬����
//��������������0��18B20��⵽�������ͺ����������������60ms
//�����������������ߺ��15us��ȡ�����ϵ�״̬
//��ȡ1λ����������Ҫ60us
unsigned char read_byte()
{
	 unsigned char  i = 0;
	 unsigned char value = 0;                                //�����¶�
	 DQ_HIGH();     
	 DELAY_US(2);
	 for(i = 8;i > 0; i--)
	 {
	   value >>= 1; 
	   DQ_LOW();
	   DELAY_US(3);                                     //������������3us
	   DQ_HIGH();                               //�����ߵ�ƽ
	   DELAY_US(7);                                //�ͷ����ߺ󱣳�7us�ٶ�ȡ����
	   if(DQ)
	   {
	   	  value |= 0x80;
	   }
	   DELAY_US(60);                               //��ʱ50us����֤ÿ1λ��60us��ʱ
	  }
	  return(value);
}

void TEM_Getinit(void)
{
	TEM_18B20_IOinit();
}
//-------------------------------------------------
//�����¶�ת������
float  get_temp(void)
{ 
	char state = 0;
	char i = 0;
	unsigned char  TLV = 22;   //�ɼ������¶ȸ�8λ
	unsigned char  THV = 22;   //�ɼ������¶ȵ�8λ
	float temp = 0;

	for(i = 0; i <= 5; i++)
	{
		state = reset();    //��λ�ȴ��ӻ�Ӧ��,if run 5 times,it means the  reset failed
		if(state == 1)
			break;
		else if(i == 5)
			return temp = 55.55;     
	} 
	DELAY_US(20); 
	write_byte(0XCC);                        //����ROMƥ�� 
	write_byte(0X44);                        //�����¶�ת������  

	DELAY_US(200000);                         //ȷ���¶�ת���������Ҫ��ʱ��                            
	for(i = 0;i<= 5; i++)		//�ٴθ�λ���ȴ��ӻ�Ӧ�� 
	{
		state = reset();    //��λ�ȴ��ӻ�Ӧ��,if run 5 times,it means the  reset failed
		if(state == 1)
			break;
		else if(i == 5)
			return temp = 44.44;     
	}
	DELAY_US(20);
	write_byte(0XCC);                        //����ROMƥ�� 
	write_byte(0XBE);                        //���Ͷ��¶�����
	 
	TLV=read_byte();                         //�����¶ȵ�8 
	THV=read_byte();                         //�����¶ȸ�8λ 
	DQ_HIGH();                               //�ͷ�����
	temp=((THV*256)+TLV)*0.0625;       
	return(temp);							//������ʵ�¶�ֵ
}
 
  
//**********************