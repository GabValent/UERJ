package view;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionListener;

import javax.swing.JTextField;
import javax.swing.JButton;

public class LoginGUI extends JFrame {

	private static final long serialVersionUID = 1L;
	private JTextField txtLoginInput;
	private JTextField txtSenhaInput;
	private JLabel lblLogin;
	private JLabel lblSenha;
	private JButton btnLimpar;
	private JButton btnEntrar;

	/**
	 * Config do frame de login, primeira tela.
	 */
	public LoginGUI() {
		//Config da tela inicial
		setTitle("Tela de Login");
		setBounds(100, 100, 450, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		getContentPane().setLayout(null);
		
		//Config do label de login
		lblLogin = new JLabel("Login");
		lblLogin.setFont(new Font("Tahoma", Font.BOLD, 14));
		lblLogin.setBounds(85, 44, 64, 17);
		getContentPane().add(lblLogin);
		
		//Config do label de senha
		lblSenha = new JLabel("Senha");
		lblSenha.setFont(new Font("Tahoma", Font.BOLD, 14));
		lblSenha.setBounds(85, 114, 64, 17);
		getContentPane().add(lblSenha);
		
		
		//Config do input de login
		txtLoginInput = new JTextField();
		txtLoginInput.setBounds(85, 72, 199, 25);
		getContentPane().add(txtLoginInput);
		txtLoginInput.setColumns(10);
		
		//Config do label de senha
		txtSenhaInput = new JTextField();
		txtSenhaInput.setColumns(10);
		txtSenhaInput.setBounds(85, 145, 199, 25);
		getContentPane().add(txtSenhaInput);
		
		//Config do botão de limpar
		btnLimpar = new JButton("Limpar");
		btnLimpar.setBounds(85, 191, 89, 23);
		getContentPane().add(btnLimpar);
		
		
		//Config do botão de entrar
		btnEntrar = new JButton("Entrar");
		btnEntrar.setBounds(195, 191, 89, 23);
		getContentPane().add(btnEntrar);
	}
	
	
	//Método para iniciar o listener do botão Entrar
    public void addLoginListener(ActionListener listener) {
    	btnEntrar.addActionListener(listener);
    }

    //Método para iniciar o listener do botão Limpar
    public void addLimparListener(ActionListener listener) {
        btnLimpar.addActionListener(listener);
    }

    //Métodos para acessar os campos de login e senha
    public String getLoginInput() {
        return txtLoginInput.getText();
    }

    public String getSenhaInput() {
        return txtSenhaInput.getText();
    }
    
    //Metodo para limpar os textos
    //Nao consegui fazer fora daqui
    public void clearInputs() {
        txtLoginInput.setText("");
        txtSenhaInput.setText("");
    }
	
}
