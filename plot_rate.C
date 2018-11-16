#include "snippet.C"

int graph_section(TString which_chamber, string which_plot, PlotterLines graphLines, PlotterLines subtraction, string subtract_or_no, string irr_or_ref, string type, int num_runs);

void plot_rate(TString which_chamber, string which_plot, string subtract_or_no, string irr_or_ref, string type, int num_runs) {
    std::cout << "\n---------- Doing " << which_chamber << ", " << which_plot << ", " << subtract_or_no << std::endl;
    ExcelSheet test(which_chamber+"/"+"final_numbers_rate.csv");
    
    //PlotterLines constructor args --
    //1st arg: excel spreadsheet
    //2nd arg: starting row (counts from 0)
    //3rd arg: ending row (counts from 0)
    //4th arg: column index (counts from 0)
    //5th arg: number of columns
    
    PlotterLines ALCT_dark(test, 2, 27, 2, num_runs);
    PlotterLines CLCT_dark(test, 2, 27, 14, num_runs);
    PlotterLines LCT_dark(test, 2, 27, 26, num_runs);
    
//    std::cout << "1" << std::endl;
    
    PlotterLines ALCT_irr_1(test, 33, 58, 2, num_runs);
    PlotterLines CLCT_irr_1(test, 33, 58, 14, num_runs);
    PlotterLines LCT_irr_1(test, 33, 58, 26, num_runs);
    
//    std::cout << "2" << std::endl;
    
    PlotterLines ALCT_irr_2(test, 64, 89, 2, num_runs);
    PlotterLines CLCT_irr_2(test, 64, 89, 14, num_runs);
    PlotterLines LCT_irr_2(test, 64, 89, 26, num_runs);
    
//    std::cout << "3" << std::endl;

    PlotterLines ALCT_ref_1(test, 94, 119, 2, num_runs);
    PlotterLines CLCT_ref_1(test, 94, 119, 14, num_runs);
    PlotterLines LCT_ref_1(test, 94, 119, 26, num_runs);
    
//    std::cout << "4" << std::endl;
    
    //andrew -- memory issues right now?
    //or something specifically wrong with this section
    //comment out this section
//    PlotterLines ALCT_ref_2(test, 126, 151, 2, num_runs);
//    PlotterLines CLCT_ref_2(test, 126, 151, 14, num_runs);
//    PlotterLines LCT_ref_2(test, 126, 151, 26, num_runs);
    
//    std::cout << "5" << std::endl;
    

    if (which_plot=="ALCT_dark"){
        graph_section(which_chamber, which_plot, ALCT_dark, ALCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
    else if (which_plot=="ALCT_irr_1"){
        graph_section(which_chamber, which_plot, ALCT_irr_1, ALCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
    else if (which_plot=="ALCT_irr_2"){
        graph_section(which_chamber, which_plot, ALCT_irr_2, ALCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
    else if (which_plot=="ALCT_ref_1"){
        graph_section(which_chamber, which_plot, ALCT_ref_1, ALCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
//    else if (which_plot=="ALCT_ref_2"){
//        graph_section(which_chamber, which_plot, ALCT_ref_2, ALCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
//    }

    else if (which_plot=="CLCT_dark"){
        graph_section(which_chamber, which_plot, CLCT_dark, CLCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
    else if (which_plot=="CLCT_irr_1"){
        graph_section(which_chamber, which_plot, CLCT_irr_1, CLCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
    else if (which_plot=="CLCT_irr_2"){
        graph_section(which_chamber, which_plot, CLCT_irr_2, CLCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
    else if (which_plot=="CLCT_ref_1"){
        graph_section(which_chamber, which_plot, CLCT_ref_1, CLCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
//    else if (which_plot=="CLCT_ref_2"){
//        graph_section(which_chamber, which_plot, CLCT_ref_2, CLCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
//    }

    else if (which_plot=="LCT_dark"){
        graph_section(which_chamber, which_plot, LCT_dark, LCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
    else if (which_plot=="LCT_irr_1"){
        graph_section(which_chamber, which_plot, LCT_irr_1, LCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
    else if (which_plot=="LCT_irr_2"){
        graph_section(which_chamber, which_plot, LCT_irr_2, LCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
    else if (which_plot=="LCT_ref_1"){
        graph_section(which_chamber, which_plot, LCT_ref_1, LCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
    }
//    else if (which_plot=="LCT_ref_2"){
//        graph_section(which_chamber, which_plot, LCT_ref_2, LCT_dark, subtract_or_no, irr_or_ref, type, num_runs);
//    }
    
}

int graph_section(TString which_chamber, string which_plot, PlotterLines graphLines, PlotterLines subtraction, string subtract_or_no, string irr_or_ref, string type, int num_runs){

    gROOT->SetBatch(true);
    gStyle->SetOptStat(2210);
//    gStyle->SetTitleAlign(23);

    int H = 800;
    int W = H;
    float T = 0.08*H;
    float B = 0.12*H;
    float L = 0.12*W;
    float R = 0.04*W;
    float x1_l = 0.48;
    float y1_l = 0.90;
    float dx_l = 0.30;
    float dy_l = 0.30;
    float x0_l = x1_l-dx_l;
    float y0_l = y1_l-dy_l;
    
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
    
    Color_t dark_use_col = kBlack;
    Color_t irr_use_col_prev = kRed;
    Color_t irr_use_col_curr = kRed+2;
    Color_t ref_use_col_prev = kBlue;
    Color_t ref_use_col_curr = kBlue+3;
    float color_trans[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    
    std::vector<int> markerStyles = {20, 21, 22, 34, 43, 29, 45, 47, 33, 41, 23, 39};
    
    TString title, sub, type_name, layer;
    if (which_chamber.Contains("chamber5")){
        if (subtract_or_no=="subtract"){
            sub = ", Background subtracted";
        }
        else if (subtract_or_no=="no"){
            sub = "";
        }
        if (irr_or_ref=="irr_1"){
            layer = " Irradiated Layer, Hole (2,2) (Irr.)";
        }
        if (irr_or_ref=="irr_2"){
            layer = " Irradiated Layer, Hole (3,1)";
        }
        else if (irr_or_ref=="ref_1"){
            layer = " Reference Layer, Hole (2,2)";
        }
        else if (irr_or_ref=="dark"){
            layer = " Dark Rate";
            sub = "";
        }
        if (type=="LCT"){
            type_name="LCT Rate:";
        }
        else if (type=="CLCT"){
            type_name="CLCT Rate:";
        }
        else if (type=="ALCT"){
            type_name="ALCT Rate:";
        }
    }
    else if (which_chamber.Contains("chamber4")){
        if (subtract_or_no=="subtract"){
            sub = ", Background subtracted";
        }
        else if (subtract_or_no=="no"){
            sub = "";
        }
        if (irr_or_ref=="irr_1"){
            layer = " Irradiated Layer, Hole (2,2)";
        }
        else if (irr_or_ref=="irr_2"){
            layer = " Irradiated Layer, Hole (3,1)";
        }
        else if (irr_or_ref=="ref_1"){
            layer = " Reference Layer, Hole (2,2)";
        }
        else if (irr_or_ref=="ref_2"){
            layer = " Reference Layer, Hole (3,1)";
        }
        else if (irr_or_ref=="dark"){
            layer = " Dark Rate";
            sub = "";
        }
        if (type=="LCT"){
            type_name="LCT Rate:";
        }
        else if (type=="CLCT"){
            type_name="CLCT Rate:";
        }
        else if (type=="ALCT"){
            type_name="ALCT Rate:";
        }
        
    }
    title = type_name+layer+sub;
    std::cout << title << std::endl;
    
    int number_of_points=graphLines.size;
    int number_of_lines=num_runs;

    // if sub_or_no = sub, then don't add the background back it (it has been subtracted in the excel document).
    // If it = no, then add the background back in to return it to the raw, un-subtracted data
    if (subtract_or_no=="subtract"){
        for (int q=0; q<number_of_lines; q++){
            for (int w=0; w<number_of_points; w++){
                subtraction.lines[q].at(w)=0;
            }
        }
    }

    TMultiGraph *mg = new TMultiGraph();
    TLegend *legend = new TLegend(x0_l,y0_l,x1_l,y1_l,"","brNDC");
    legend->SetBorderSize(1);
    
    //loop over number of runs
    for (int j=0; j<number_of_lines; j++){
        //Create the graph by looping over the number of points
        TGraph *graph = new TGraph(number_of_points);
        //loop over voltages
        for (int i=0; i<number_of_points; i++){
            if (graphLines.lines[j].at(i)<0){
                // Note that we are using the .voltages here, this is specific to the rate plots, and it automatically picks the "0" column, where the voltages are located.
                graph->SetPoint(i, graphLines.voltages.at(i),0);
            }
            else{
                graph->SetPoint(i,graphLines.voltages.at(i),graphLines.lines[j].at(i)+subtraction.lines[j].at(i));
            }
        }

        Color_t color=ref_use_col_prev;
        float transparency = color_trans[j];
        if (irr_or_ref=="irr_1" || irr_or_ref=="irr_2"){
            color = irr_use_col_prev;
        }
        else if (irr_or_ref=="dark"){
            color = dark_use_col;
        }
        if (j==number_of_lines-1){
            transparency=1;
            color=ref_use_col_curr;
            if (irr_or_ref=="irr_1" || irr_or_ref=="irr_2"){
                color=irr_use_col_curr;
            }
            else if (irr_or_ref=="dark"){
                color = dark_use_col;
            }
        }
        graph->SetLineColorAlpha(color, transparency);
        graph->SetLineWidth(2.0);
        graph->SetMarkerStyle(markerStyles[j]);
        graph->SetMarkerSize(1.7);
        graph->SetMarkerColorAlpha(color, transparency);
        graph->SetTitle(title);

        if (which_chamber=="chamber5"){
            std::vector<int> acc_charges = {0, 53, 95, 121, 149, 180, 209, 235, 0, 0, 0};
            TString legendname = "Run "+to_string(j)+", "+to_string(acc_charges[j])+" mC/cm";
            legend->AddEntry(graph, legendname, "P");
        }
        else if (which_chamber=="chamber4"){
            std::vector<int> acc_charges = {0, 17, 26, 68, 123, 157, 188, 0, 0, 0, 0};
            TString legendname = "Run "+to_string(j)+", "+to_string(acc_charges[j])+" mC/cm";
            legend->AddEntry(graph, legendname, "P");
        }
        
        mg->Add(graph);
    }
    
    mg->GetXaxis()->SetTitle("Voltage (kV)");
    mg->GetYaxis()->SetTitle("Hertz");
    mg->SetTitle(title);
    mg->GetXaxis()->SetRangeUser(2,4);
    int ymax = 500;
    mg->SetMaximum(ymax);

    canvas->cd();
    mg->Draw("ALP");
	legend->Draw("SAME");
    
    canvas->Update();
    TLine *line = new TLine(3.6, 0, 3.6, ymax);
    line->SetLineColor(kPink-9);
    line->SetLineWidth(2.0);
    line->Draw();
    
    system("mkdir -p "+which_chamber+"/"+"Plots/");
    TString saveWhere;
    if (irr_or_ref=="dark"){
        saveWhere = which_chamber+"/"+"Plots/"+which_plot+".pdf";
    }
    else{
        saveWhere = which_chamber+"/"+"Plots/"+which_plot+"_"+subtract_or_no+".pdf";
    }
	canvas->Update();
    canvas->SaveAs(saveWhere);
    canvas;

	return 0;
}

