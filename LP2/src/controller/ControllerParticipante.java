package controller;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import model.Participante;
import view.ParticipanteGUI;


public class ControllerParticipante {
	private ParticipanteGUI tela;
	
	public ControllerParticipante() {
		//inicia a tela
        tela = new ParticipanteGUI();
        // Adiciona os listeners
        tela.addLimparListener(new OuvinteLimpar());
        tela.addCadasListener(new OuvinteCadastrar());
        tela.setVisible(true); 
    }
	
	
	// Listener para o botão Limpar
    class OuvinteLimpar implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
        	//chama metodo da tela
            tela.clearInputs();
        }
    }
    
 // Listener para o botão Cadastrar
    class OuvinteCadastrar implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
        	String nome = tela.getTxtNomeInput();
            String matricula = tela.getTxtMatricInput();
            String curso = tela.getTxtCursoInput();
            String evento = tela.getComboItem();
        	Participante p = new Participante(nome, matricula, curso, evento);
            Object[] dados = {p.getNome(), p.getMatricula(), p.getCurso(), p.getEvento()};
        	tela.addItem(dados);
        	tela.clearInputs();
        }
    }
}
