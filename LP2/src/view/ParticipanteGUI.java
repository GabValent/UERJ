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

/**
 * Interface gráfica para o cadastro de participantes.
 */
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
     * Método principal para iniciar a aplicação.
     *
     * @param args argumentos de linha de comando
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
     * Construtor: Cria o frame da interface gráfica.
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

        String[] colunas = {"Nome", "Matrícula", "Curso", "Evento"};
        modeloTabela = new DefaultTableModel(null, colunas);
        tabela = new JTable(modeloTabela);

        scrollPane = new JScrollPane(tabela);
        scrollPane.setBounds(10, 329, 414, 129);
        getContentPane().add(scrollPane);
        scrollPane.setVisible(false);
    }

    /**
     * Retorna o texto inserido no campo de nome.
     *
     * @return texto do campo de nome
     */
    public String getTxtNomeInput() {
        return txtNomeInput.getText();
    }

    /**
     * Retorna o texto inserido no campo de matrícula.
     *
     * @return texto do campo de matrícula
     */
    public String getTxtMatricInput() {
        return txtMatricInput.getText();
    }

    /**
     * Retorna o texto inserido no campo de curso.
     *
     * @return texto do campo de curso
     */
    public String getTxtCursoInput() {
        return txtCursoInput.getText();
    }

    /**
     * Retorna o item selecionado no comboBox de eventos.
     *
     * @return item selecionado no comboBox
     */
    public String getComboItem() {
        return (String) comboBox.getSelectedItem();
    }

    /**
     * Adiciona um listener ao botão Limpar.
     *
     * @param listener listener para o botão Limpar
     */
    public void addLimparListener(ActionListener listener) {
        btnLimpar.addActionListener(listener);
    }

    /**
     * Adiciona um listener ao botão Cadastrar.
     *
     * @param listener listener para o botão Cadastrar
     */
    public void addCadasListener(ActionListener listener) {
        btnCadastrar.addActionListener(listener);
    }

    /**
     * Adiciona um item à tabela.
     *
     * @param item array de objetos representando o item a ser adicionado
     */
    public void addItem(Object[] item) {
        modeloTabela.addRow(item);
        scrollPane.setVisible(true);
    }

    /**
     * Limpa os campos de entrada de texto.
     */
    public void clearInputs() {
        txtNomeInput.setText("");
        txtMatricInput.setText("");
        txtCursoInput.setText("");
    }
}
