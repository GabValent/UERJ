package view;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JTable;

import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class ParticipanteGUI extends JFrame {

	private static final long serialVersionUID = 1L;
	private JTextField txtNomeInput;
	private JLabel lblNome;
	private JTextField txtMatricInput;
	private JLabel lblMatricula;
	private JTextField txtCursoInput;
	private JLabel lblCurso;
	private JLabel lblEvento;
	private JComboBox comboBox;
	private JButton btnLimpar;
	private JTable tabela;
	private DefaultTableModel modeloTabela;
	private JScrollPane scrollPane;
	private JButton btnCadastrar;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ParticipanteGUI frame = new ParticipanteGUI();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public ParticipanteGUI() {
		setTitle("CADASTRO DE PARTICIPANTES");
		setBounds(100, 100, 450, 508);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		getContentPane().setLayout(null);
		
		lblNome = new JLabel("Nome");
		lblNome.setFont(new Font("Tahoma", Font.BOLD, 14));
		lblNome.setBounds(97, 24, 46, 14);
		getContentPane().add(lblNome);
		
		txtNomeInput = new JTextField();
		txtNomeInput.setBounds(97, 49, 211, 26);
		getContentPane().add(txtNomeInput);
		txtNomeInput.setColumns(10);
		
		lblMatricula = new JLabel("Matricula");
		lblMatricula.setFont(new Font("Tahoma", Font.BOLD, 14));
		lblMatricula.setBounds(97, 86, 86, 17);
		getContentPane().add(lblMatricula);
		
		txtMatricInput = new JTextField();
		txtMatricInput.setBounds(97, 114, 211, 26);
		getContentPane().add(txtMatricInput);
		txtMatricInput.setColumns(10);
		
		lblCurso = new JLabel("Curso");
		lblCurso.setFont(new Font("Tahoma", Font.BOLD, 14));
		lblCurso.setBounds(97, 151, 46, 14);
		getContentPane().add(lblCurso);
		
		txtCursoInput = new JTextField();
		txtCursoInput.setBounds(97, 176, 211, 26);
		getContentPane().add(txtCursoInput);
		txtCursoInput.setColumns(10);
		
		lblEvento = new JLabel("Evento Desejado");
		lblEvento.setFont(new Font("Tahoma", Font.BOLD, 14));
		lblEvento.setBounds(97, 213, 149, 26);
		getContentPane().add(lblEvento);

		btnLimpar = new JButton("Limpar");
		btnLimpar.setBounds(94, 295, 89, 23);
		getContentPane().add(btnLimpar);
		
		btnCadastrar = new JButton("Cadastrar");
		btnCadastrar.setBounds(219, 295, 89, 23);
		getContentPane().add(btnCadastrar);
		
		comboBox = new JComboBox();
		comboBox.setFont(new Font("Tahoma", Font.BOLD, 12));
		comboBox.setModel(new DefaultComboBoxModel(new String[] {"Semana do IME", "SEMIC", "Semana de Extensão", "Palestra IA e seus desafios"}));
		comboBox.setBounds(94, 250, 214, 34);
		getContentPane().add(comboBox);
		
		
		String[] colunas = {"Nome","Matrícula","Curso","Evento"};
		modeloTabela = new DefaultTableModel(null,colunas);
		tabela = new JTable(modeloTabela);
		
		scrollPane = new JScrollPane(tabela);
		scrollPane.setBounds(10, 329, 414, 129);
		getContentPane().add(scrollPane);
		scrollPane.setVisible(false);
		
	
		
		

	}

	public String getTxtNomeInput() {
		return txtNomeInput.getText();
	}

	public String getTxtMatricInput() {
		return txtMatricInput.getText();
	}

	public String getTxtCursoInput() {
		return txtCursoInput.getText();
	}
	
	public String getComboItem() {
		return (String) comboBox.getSelectedItem();
	}
	
	//Método para iniciar o listener do botão Limpar
    public void addLimparListener(ActionListener listener) {
        btnLimpar.addActionListener(listener);
    }
    
  //Método para iniciar o listener do botão Cadastrar
    public void addCadasListener(ActionListener listener) {
        btnCadastrar.addActionListener(listener);
    }
    
	public void addItem(Object[] item) {
		modeloTabela.addRow(item);
		scrollPane.setVisible(true);
	}
    
    
	public void clearInputs() {
		txtNomeInput.setText("");
		txtMatricInput.setText("");
		txtCursoInput.setText("");
		
    }
	
	
	

	

}
