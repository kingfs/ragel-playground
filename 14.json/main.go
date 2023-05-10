package main

import (
	"fmt"
	"os"
	"io/ioutil"
	"log"
	"main/config"
	"main/scanner"
	"main/token"

	"github.com/urfave/cli/v2"
)

const (
	DefaultPoolSize = 100
)

func TravelSubTokens(tokens []token.Token, r int) {
	if len(tokens) == 0 {
		r -= 1
		return
	} else {
		r += 1
	}

	for _, i := range tokens {
		for t := 1; t < r; t++ {
			fmt.Printf("\t")
		}

		fmt.Printf(
			"Type: %s\tValue:%s\r\n", i.ID, i.Value)

		TravelSubTokens(i.SubTokens, r)
	}


}

func main() {
	app := &cli.App{
		Flags: []cli.Flag{
			&cli.StringFlag{
				Name: "file",
				Aliases: []string{"f"},
				Usage: "load json content from `FILE`",
			},
			&cli.StringFlag{
				Name: "config",
				Aliases: []string{"c"},
				Usage: "load configuration file",
			},
		},
		Action: func(c *cli.Context) error {
			var cc config.Config

			if c.String("file") == "" {
				return fmt.Errorf("can't load json content")
			}
			if c.String("config") == "" {
				cc.PoolSize = DefaultPoolSize
			}


			data, err := ioutil.ReadFile(c.String("file"))
			if err != nil {
				log.Fatalln(err)
			}

			lex := scanner.NewLexer([]byte(data), cc)

			res := lex.Lex()
			fmt.Printf(
				"Type: %s\r\nValue:%s\r\n", res.ID, res.Value)

			TravelSubTokens(res.SubTokens, 1)

			return nil
		},
	}
	err := app.Run(os.Args)
	if err != nil {
		log.Fatal(err)
	}

	// data := "[\r\n 123," + `"hello"` + "\r\n, [123, \r\n, 789]]"

}
