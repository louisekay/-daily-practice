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
		textShow.append(str + "的长度" + str.length() + "\n");
	}
}

public class Windowplay
{
	public static void main(String args[])
	{
		JFrame mainWindow = new JFrame("主窗口");
		mainWindow.setVisible(true);//初始化，这里只是把窗口显示，然后在下面进行的操作并不会显示出来，还要在操作完以后再刷新一次
		mainWindow.setBounds(100,100,700,500);
		mainWindow.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		JTextField inputText = new JTextField(10);//定义组件
		JTextArea textShow = new JTextArea(9,30);
		JButton button = new JButton("确定");
	
		EditListen listener = new EditListen();
		
		
		listener.setTextf(inputText);
		listener.setTexta(textShow);
		
		mainWindow.setLayout(new FlowLayout());//添加
		mainWindow.add(inputText);
		mainWindow.add(button);
		mainWindow.add(new JScrollPane(textShow));
		inputText.addActionListener(listener);
		button.addActionListener(listener);
		mainWindow.setVisible(true);//相当于刷新
	}
}