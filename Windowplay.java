import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

 class EditListen implements ActionListener
{
	JTextField textInput;
	JTextArea textShow;
	 void setTextf(JTextField text)
	{
		textInput = text;
	}
	 void setTexta(JTextArea area)
	{
		textShow = area;
	}
	public void actionPerformed(ActionEvent e)
	{
		String str = textInput.getText();
		textShow.append(str + "�ĳ���" + str.length() + "\n");
	}
}

public class Windowplay
{
	public static void main(String args[])
	{
		JFrame mainWindow = new JFrame("������");
		mainWindow.setVisible(true);//��ʼ��������ֻ�ǰѴ�����ʾ��Ȼ����������еĲ�����������ʾ��������Ҫ�ڲ������Ժ���ˢ��һ��
		mainWindow.setBounds(100,100,700,500);
		mainWindow.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		JTextField inputText = new JTextField(10);//�������
		JTextArea textShow = new JTextArea(9,30);
		JButton button = new JButton("ȷ��");
	
		EditListen listener = new EditListen();
		
		
		listener.setTextf(inputText);
		listener.setTexta(textShow);
		
		mainWindow.setLayout(new FlowLayout());//���
		mainWindow.add(inputText);
		mainWindow.add(button);
		mainWindow.add(new JScrollPane(textShow));
		inputText.addActionListener(listener);
		button.addActionListener(listener);
		mainWindow.setVisible(true);//�൱��ˢ��
	}
}