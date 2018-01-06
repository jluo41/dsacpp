
#pragma once

template <typename T> //��㹹���㷨��ͨ������Ԫ��λ�ù�������[lo, hi]����㣬����������
Rank Vector<T>::partition ( Rank lo, Rank hi ) { //�汾B�����Ż���������ؼ�����ͬ���˻����
   swap ( _elem[lo], _elem[lo + rand() % ( hi - lo + 1 ) ] ); //��ѡһ��Ԫ������Ԫ�ؽ���
   T pivot = _elem[lo]; //����Ԫ��Ϊ��ѡ��㡪�������Ͻ�������Ч�����ѡȡ
   while ( lo < hi ) { //�����������˽�������м�ɨ��
      while ( lo < hi )
         if ( pivot < _elem[hi] ) //�ڴ���pivot��ǰ����
            hi--; //������չ�Ҷ�������
         else //ֱ������������pivot��
            { _elem[lo++] = _elem[hi]; break; } //����������������
      while ( lo < hi )
         if ( _elem[lo] < pivot ) //��С��pivot��ǰ����
            lo++; //������չ���������
         else //ֱ��������С��pivot��
            { _elem[hi--] = _elem[lo]; break; } //��������Ҷ�������
   } //assert: lo == hi
   _elem[lo] = pivot; //�����ݵ�����¼����ǰ����������֮��
   return lo; //����������
}