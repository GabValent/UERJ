package view;

import java.awt.Font;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

/**
 * Config do frame de login, primeira tela .
 */
public class LoginGUI extends JFrame {

    private static final long serialVersionUID = 1L;
    private JTextField txtLoginInput;
    private JTextField txtSenhaInput;
    private JLabel lblLogin;
    private JLabel lblSenha;
    private JButton btnLimpar;
    private JButton btnEntrar;

    /**
     * Construtor: Config da tela inicial.
     */
    public LoginGUI() {
        setTitle("Tela de Login");
        setBounds(100, 100, 450, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        getContentPane().setLayout(null);

        // Config do label de login
        lblLogin = new JLabel("Login");
        lblLogin.setFont(new Font("Tahoma", Font.BOLD, 14));
        lblLogin.setBounds(85, 44, 64, 17);
        getContentPane().add(lblLogin);

        // Config do label de senha
        lblSenha = new JLabel("Senha");
        lblSenha.setFont(new Font("Tahoma", Font.BOLD, 14));
        lblSenha.setBounds(85, 114, 64, 17);
        getContentPane().add(lblSenha);

        // Config do input de login
        txtLoginInput = new JTextField();
        txtLoginInput.setBounds(85, 72, 199, 25);
        getContentPane().add(txtLoginInput);
        txtLoginInput.setColumns(10);

        // Config do input de senha
        txtSenhaInput = new JTextField();
        txtSenhaInput.setColumns(10);
        txtSenhaInput.setBounds(85, 145, 199, 25);
        getContentPane().add(txtSenhaInput);

        // Config do botão de limpar
        btnLimpar = new JButton("Limpar");
        btnLimpar.setBounds(85, 191, 89, 23);
        getContentPane().add(btnLimpar);

        // Config do botão de entrar
        btnEntrar = new JButton("Entrar");
        btnEntrar.setBounds(195, 191, 89, 23);
        getContentPane().add(btnEntrar);
    }

    /**
     * Método para iniciar o listener do botão Entrar.
     *
     * @param listener o listener para o botão Entrar
     */
    public void addLoginListener(ActionListener listener) {
        btnEntrar.addActionListener(listener);
    }

    /**
     * Método para iniciar o listener do botão Limpar.
     *
     * @param listener o listener para o botão Limpar
     */
    public void addLimparListener(ActionListener listener) {
        btnLimpar.addActionListener(listener);
    }

    /**
     * Método para acessar os campos de login.
     *
     * @return o texto do campo de login
     */
    public String getLoginInput() {
        return txtLoginInput.getText();
    }

    /**
     * Método para acessar os campos de senha.
     *
     * @return o texto do campo de senha
     */
    public String getSenhaInput() {
        return txtSenhaInput.getText();
    }

    /**
     * Método para limpar os textos.
     *
     */
    public void clearInputs() {
        txtLoginInput.setText("");
        txtSenhaInput.setText("");
    }
}
