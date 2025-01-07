package controller;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JOptionPane;

import view.LoginGUI;

/**
 * Controlador responsável por gerenciar a tela de login {@link LoginGUI}.
 * 
 */
public class ControllerTelaLogin {
    private LoginGUI tela;

    /**
     * Construtor: Inicia a tela de login e adiciona os listeners.
     */
    public ControllerTelaLogin() {
        // Inicia a tela
        tela = new LoginGUI();
        // Adiciona os listeners
        tela.addLoginListener(new OuvinteLogin());
        tela.addLimparListener(new OuvinteLimpar());
        tela.setVisible(true);
    }

    /**
     * Listener para o botão Entrar.
     */
    class OuvinteLogin implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String login = tela.getLoginInput();
            String senha = tela.getSenhaInput();

            // Implementar lógica de autenticação aqui
            if (login.equals("aluno") && senha.equals("2024")) {
                JOptionPane.showMessageDialog(tela, "Seja bem-vindo!", "Login aceito", JOptionPane.INFORMATION_MESSAGE);
                tela.setVisible(false);
                ControllerParticipante controller_2 = new ControllerParticipante();
            } else {
                JOptionPane.showMessageDialog(tela, "Login ou senha inválidos!", "Login rejeitado, tente novamente", JOptionPane.INFORMATION_MESSAGE);
                tela.clearInputs();
            }
        }
    }

    /**
     * Listener para o botão Limpar.
     */
    class OuvinteLimpar implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            // Chama o método da tela
            tela.clearInputs();
        }
    }
}