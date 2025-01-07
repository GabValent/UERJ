package controller;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JOptionPane;

import model.Participante;
import view.ParticipanteGUI;

/**
 * Controlador para gerenciar as interações entre a GUI de Participante e o modelo {@link Participante} {@link ParticipanteGUI}.
 */
public class ControllerParticipante {
    private ParticipanteGUI tela;

    /**
     * Construtor: Inicializa a tela e adiciona os listeners necessários.
     */
    public ControllerParticipante() {
        // inicia a tela
        tela = new ParticipanteGUI();
        // Adiciona os listeners
        tela.addLimparListener(new OuvinteLimpar());
        tela.addCadasListener(new OuvinteCadastrar());
        tela.addWindowListener(new FecharJanela());
        tela.setVisible(true);
    }

    /**
     * Listener para o botão Limpar.
     */
    class OuvinteLimpar implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            // chama método da tela
            tela.clearInputs();
        }
    }

    /**
     * Listener para o botão Cadastrar.
     */
    class OuvinteCadastrar implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String nome = tela.getTxtNomeInput();
            String matricula = tela.getTxtMatricInput();
            String curso = tela.getTxtCursoInput();
            String evento = tela.getComboItem();

            // Validação dos campos
            if (nome.isEmpty() || matricula.isEmpty() || curso.isEmpty()) {
                JOptionPane.showMessageDialog(tela, "Preencha todos os campos!", "Erro", JOptionPane.ERROR_MESSAGE);
                return;
            }

            Participante p = new Participante(nome, matricula, curso, evento);
            Object[] dados = {p.getNome(), p.getMatricula(), p.getCurso(), p.getEvento()};
            tela.addItem(dados);
            tela.clearInputs();
            JOptionPane.showMessageDialog(tela, "Participante cadastrado com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    /**
     * Listener para confirmar antes de fechar a janela.
     */
    class FecharJanela extends WindowAdapter {
        @Override
        public void windowClosing(WindowEvent e) {
            int resposta = JOptionPane.showConfirmDialog(tela, "Deseja realmente sair?", "Confirmação", JOptionPane.YES_NO_OPTION);
            if (resposta == JOptionPane.NO_OPTION) {
                tela.setDefaultCloseOperation(ParticipanteGUI.DO_NOTHING_ON_CLOSE);
            } else {
                tela.setDefaultCloseOperation(ParticipanteGUI.EXIT_ON_CLOSE);
            }
        }
    }
}
