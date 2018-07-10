#include "snippet.C"

int graph_section(string filename, string norm_or_no, PlotterLines hole_num, PlotterLines run_0, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4);
TGraph* make_graph(string norm_or_no, int i, PlotterLines run_0, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4);
float Get_average_val_irr(PlotterLines run);
float Get_average_val_ref(PlotterLines run);
TGraph* format_me(TGraph* graph, Color_t color);

void cluster_charge_plot(string which_plot, string norm_or_no) {
    ExcelSheet test("analysis_page_cluster.csv");

    // This is the important bit! The first value refers to the excel sheet above. The second number is
    // the row you start on. The second number is the lowest row you go to. Doesn't have to be exact,
    // we have a function that makes things perfect. The 3rd number is the column that you're pulling. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
    
    PlotterLines hole_num(test, 2, 13, 0, 1);
    PlotterLines run_0(test, 2, 13, 1, 1);
    //PlotterLines run_1(test, 2, 13, 3, 1);
    PlotterLines run_2(test, 2, 13, 5, 1);
    PlotterLines run_3(test, 2, 13, 7, 1);
    PlotterLines run_4(test, 2, 13, 9, 1);

    graph_section(which_plot,norm_or_no, hole_num, run_0, run_2, run_3, run_4);
}

float Get_average_val_irr(PlotterLines run){
    float tot=0;
    float divide=6;
    for (int i=0;i<6;i++){
        if (run.lines[0].at(i)==0){
            divide=divide-1;
            continue;
        }
        tot = tot+run.lines[0].at(i);
    }
    return tot/divide;
}

float Get_average_val_ref(PlotterLines run){
    float divide=6;
    float tot=0;
    for (int i=0;i<6;i++){
        if (run.lines[0].at(i)==0){
            divide=divide-1;
            continue;
        }
        tot = tot+run.lines[0].at(i);
    }
    return tot/divide;
}

// Makes the graphs
TGraph* make_graph(string norm_or_no, int i, PlotterLines run_0, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4){
    TGraph *graph = new TGraph(4);
    

    
    
    // Note the the first number is the "point number" and will always be 0-4, the second number the the run number (will be accumulated charge at some point), and the last number is charge mean
    if (norm_or_no=="irr"){
        graph->SetPoint(0, 0, run_0.lines[0].at(i)/Get_average_val_irr(run_0));
        graph->SetPoint(1, 26, run_2.lines[0].at(i)/Get_average_val_irr(run_2));
        graph->SetPoint(2, 65, run_3.lines[0].at(i)/Get_average_val_irr(run_3));
        graph->SetPoint(3, 125, run_4.lines[0].at(i)/Get_average_val_irr(run_4));
    }
    else if (norm_or_no=="ref"){
        graph->SetPoint(0, 0, run_0.lines[0].at(i)/Get_average_val_ref(run_0));
        graph->SetPoint(1, 26, run_2.lines[0].at(i)/Get_average_val_ref(run_2));
        graph->SetPoint(2, 65, run_3.lines[0].at(i)/Get_average_val_ref(run_3));
        graph->SetPoint(3, 125, run_4.lines[0].at(i)/Get_average_val_ref(run_4));
    }
    else{
        graph->SetPoint(0, 0, run_0.lines[0].at(i));
        graph->SetPoint(1, 26, run_2.lines[0].at(i));
        graph->SetPoint(2, 65, run_3.lines[0].at(i));
        graph->SetPoint(3, 125, run_4.lines[0].at(i));
    }
    return graph;
}

TGraph* format_me(TGraph* graph, Color_t color){
    graph->SetLineColor(color);
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.8);
    graph->SetMarkerColor(color);
    graph->SetLineWidth(2.0);
    
    return graph;
}



int graph_section(string filename, string norm_or_no, PlotterLines hole_num, PlotterLines run_0, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4){
	
    TString title;
    TString label;
    label = " ";
    if (norm_or_no=="ref"){
        label = ", normalized to reference layer";
    }
    title = "Cluster charge"+label;
    
    
    
    // For this plot, the "i" in graphLine.line[thing].at(i) refers to which hole is being sourced. Guidlines here:
    // Top (1,1): i=0
    // Top (1,2): i=1
    // Top (2,1): i=2
    // Top (2,2): i=3
    // Top (3,1): i=4
    // Top (3,2): i=5
    // Bottom (1,1): i=6
    // Bottom (1,2): i=7
    // Bottom (2,1): i=8
    // Bottom (2,2): i=9
    // Bottom (3,1): i=10
    // Bottom (3,2): i=11
    
    
    Color_t colors[] = {kRed, kRed+3, kRed-6, kOrange-3, kRed-3, kOrange+4, kBlue-10, kBlue-7, kBlue, kBlue+2, kAzure+4, kAzure+1};
    
	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
	gStyle->SetTitleAlign(23);

	//References for changing margins and the size of the canvas
	int H = 800;
	int W = H;
	float T = 0.08*H;
	float B = 0.12*H;
	float L = 0.12*W;
	float R = 0.04*W;
	float x1_l = 0.38;
	float y1_l = 0.90;
	float dx_l = 0.20;
	float dy_l = 0.20;
	float x0_l = x1_l-dx_l;
	float y0_l = y1_l-dy_l;

	//make the canvas, set its properties
	TCanvas *canvas = new TCanvas("c2","c2",50,50,W,H);
	canvas->SetFillColor(0);
	canvas->SetBorderMode(0);
	canvas->SetFrameFillStyle(0);
	canvas->SetFrameBorderMode(0);
	canvas->SetLeftMargin( L/W );
	canvas->SetRightMargin( R/W );
	canvas->SetTopMargin( T/H );
	canvas->SetBottomMargin( B/H );
	canvas->cd();

	//the legend happens
	TLegend *legend = new TLegend(x0_l,y0_l,x1_l,y1_l,"","brNDC");
	legend->SetBorderSize(1);

    // This function takes the line (which has been correctly sized), and then loops through and returns graphs.
    TGraph* graph_1_1 = make_graph(norm_or_no,0,run_0, run_2, run_3, run_4);
    TGraph* graph_1_2 = make_graph(norm_or_no,1,run_0, run_2, run_3, run_4);
    TGraph* graph_2_1 = make_graph(norm_or_no,2,run_0, run_2, run_3, run_4);
    TGraph* graph_2_2 = make_graph(norm_or_no,3,run_0, run_2, run_3, run_4);
    TGraph* graph_3_1 = make_graph(norm_or_no,4,run_0, run_2, run_3, run_4);
    TGraph* graph_3_2 = make_graph(norm_or_no,5,run_0, run_2, run_3, run_4);
    
    TGraph* graph_bot_1_1 = make_graph(norm_or_no,6,run_0, run_2, run_3, run_4);
    TGraph* graph_bot_1_2 = make_graph(norm_or_no,7,run_0, run_2, run_3, run_4);
    TGraph* graph_bot_2_1 = make_graph(norm_or_no,8,run_0, run_2, run_3, run_4);
    TGraph* graph_bot_2_2 = make_graph(norm_or_no,9,run_0, run_2, run_3, run_4);
    TGraph* graph_bot_3_1 = make_graph(norm_or_no,10,run_0, run_2, run_3, run_4);
    TGraph* graph_bot_3_2 = make_graph(norm_or_no,11,run_0, run_2, run_3, run_4);
    
    
    TGraph* fin_graph_1_1 = format_me(graph_1_1, colors[0]);
    TGraph* fin_graph_1_2 = format_me(graph_1_2, colors[1]);
    TGraph* fin_graph_2_1 = format_me(graph_2_1, colors[2]);
    TGraph* fin_graph_2_2 = format_me(graph_2_2, colors[3]);
    TGraph* fin_graph_3_1 = format_me(graph_3_1, colors[4]);
    TGraph* fin_graph_3_2 = format_me(graph_3_2, colors[5]);
    
    
    // Format everything
    TGraph* fin_graph_bot_1_1 = format_me(graph_bot_1_1, colors[6]);
    TGraph* fin_graph_bot_1_2 = format_me(graph_bot_1_2, colors[7]);
    TGraph* fin_graph_bot_2_1 = format_me(graph_bot_2_1, colors[8]);
    TGraph* fin_graph_bot_2_2 = format_me(graph_bot_2_2, colors[9]);
    TGraph* fin_graph_bot_3_1 = format_me(graph_bot_3_1, colors[10]);
    TGraph* fin_graph_bot_3_2 = format_me(graph_bot_3_2, colors[11]);
    
    
    
    // Still the legend, label by hand
    legend->AddEntry(fin_graph_bot_1_1, "Irr (1,1)");
    legend->AddEntry(fin_graph_bot_1_2, "Irr (1,2)");
    legend->AddEntry(fin_graph_bot_2_1, "Irr (2,1)");
    legend->AddEntry(fin_graph_bot_2_2, "Irr (2,2)");
    legend->AddEntry(fin_graph_bot_3_1, "Irr (3,1)");
    legend->AddEntry(fin_graph_bot_3_2, "Irr (3,2)");
    
    if (norm_or_no!="ref"){
        legend->AddEntry(fin_graph_1_1, "Ref (1,1)");
        legend->AddEntry(fin_graph_1_2, "Ref (1,2)");
        legend->AddEntry(fin_graph_2_1, "Ref (2,1)");
        legend->AddEntry(fin_graph_2_2, "Ref (2,2)");
        legend->AddEntry(fin_graph_3_1, "Ref (3,1)");
        legend->AddEntry(fin_graph_3_2, "Ref (3,2)");
    }
        
        
    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    
    if (norm_or_no!="ref"){
        mg->Add(fin_graph_1_1);
        mg->Add(fin_graph_1_2);
        mg->Add(fin_graph_2_1);
        mg->Add(fin_graph_2_2);
        mg->Add(fin_graph_3_1);
        mg->Add(fin_graph_3_2);
    }
    
    
    mg->Add(fin_graph_bot_1_1);
    mg->Add(fin_graph_bot_1_2);
    mg->Add(fin_graph_bot_2_1);
    mg->Add(fin_graph_bot_2_2);
    mg->Add(fin_graph_bot_3_1);
    mg->Add(fin_graph_bot_3_2);
    
    // title!
    mg->SetTitle(title);
    
    mg->Draw("ALP");

    
    //  label
    mg->GetXaxis()->SetTitle("Accumulated charge (mC/cm)");
    mg->GetYaxis()->SetTitle("ADC counts");
    if (norm_or_no=="ref" or norm_or_no=="irr"){
        mg->GetYaxis()->SetRangeUser(0.9, 1.3);
    }

	legend->Draw("SAME");

    // Locate where it goes and gets saved, may have to be changed.
	string saveWhere = "/Users/marctost/Desktop/cluster_"+filename+norm_or_no+".png";
	canvas->Update();
	canvas->SaveAs(saveWhere.c_str());
	canvas;

	return 0;
}
